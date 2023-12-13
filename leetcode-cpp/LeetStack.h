#ifndef __LEET_STACK_H__
#define __LEET_STACK_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetStack {
 public:
  LeetStack() {}
  ~LeetStack() {}

 public:
  // leetcode1021 删除最外层的括号
  std::string removeOuterParentheses(std::string s);
  // leetcode1047 删除字符串中的所有相邻重复项
  std::string removeDuplicates(std::string s);
  // leetcode71 简化路径
  std::string simplifyPath(std::string path);

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  //  leetcode739 每日温度 单调栈模板
  static vector<int> dailyTemperatures(vector<int>& tem) {
    // 相比较而言,从右向左遍历更优秀
#if 0
    // 从右向左遍历，stack中存储单调递减（严格单调递减）对应的index
    int n = tem.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int t = tem[i];
      while (!st.empty() && t >= tem[st.top()]) {
        st.pop();
      }
      if (!st.empty()) {
        res[i] = st.top() - i;
      }
      st.push(i);
    }
    return res;
#else
    // 从左向右遍历，stack中存储单调递减（严格单调递减）对应的index
    int n = tem.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      int t = tem[i];
      while (!st.empty() && t > tem[st.top()]) {
        int j = st.top();
        st.pop();
        res[j] = i - j;
      }
      st.push(i);
    }
    return res;
#endif
  }

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  // leetcode1475 商品折扣后的最终价格
  vector<int> finalPrices(vector<int>& p) {
    // 单调栈，从右向左遍历
    // 正常的单调栈目标：寻找下一个更大的值（等于不行），本题的目标：寻找下一个小于等于本元素的值
    vector<int> res;
    for (int x : p) {
      res.emplace_back(x);
    }
    int n = p.size();
    vector<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int x = p[i];
      while (!st.empty() && x < p[st.back()]) {
        st.pop_back();
      }
      if (!st.empty()) {
        res[i] -= p[st.back()];
      }
      st.emplace_back(i);
    }
    return res;
  }

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  // leetcode496 下一个更大元素I
  std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                      std::vector<int>& nums2) {
    // ans 20231105
    // 栈+哈希表
    // 倒序遍历nums2，得到每一个数字的下一个更大值（使用栈做辅助）,并使用哈希表存储(在数组没有重复数字的前提下)
    // O(nums1.size() + nums2.size())
    std::vector<int> res;
    std::unordered_map<int, int> map;
    std::vector<int> st;
    int n = (int)nums2.size();
    for (int i = n - 1; i >= 0; i--) {
      int cur = nums2[i];
      while (!st.empty() && cur > st.back()) {
        st.pop_back();
      }
      if (st.empty()) {
        map[cur] = -1;
      } else {
        map[cur] = st.back();
      }
      st.emplace_back(cur);
    }

    for (int n : nums1) {
      res.emplace_back(map[n]);
    }

    return res;
  }

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  // leetcode503 下一个更大元素II
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nums2(nums);
    for (int x : nums) {
      nums2.emplace_back(x);
    }
    vector<int> st;
    vector<int> arr(2 * n);
    for (int i = 2 * n - 1; i >= 0; i--) {
      int x = nums2[i];
      while (!st.empty() && x >= st.back()) {
        st.pop_back();
      }
      if (!st.empty()) {
        arr[i] = st.back();
      } else {
        arr[i] = -1;
      }
      st.emplace_back(x);
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = arr[i];
    }

    return res;
  }

  vector<int> res;
  vector<int> st;
  void f1019(ListNode* node, int i) {
    if (node == nullptr) {
      res.resize(i);
      return;
    }
    f1019(node->next, i + 1);
    while (!st.empty() && node->val >= st.back()) {
      st.pop_back();
    }
    if (!st.empty()) res[i] = st.back();
    st.emplace_back(node->val);
  }

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  // leetcode1019 链表中的下一个更大节点
  vector<int> nextLargerNodes(ListNode* head) {
    f1019(head, 0);
    return res;
  }

  // leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==>
  // leetcode1019 <==> leetcode901
  // leetcode901 股票价格跨度
  class StockSpanner {
    int cur_day = -1;
    vector<pair<int, int>> st;
    int n = 0;

   public:
    StockSpanner() { st.emplace_back(-1, INT_MAX); }

    int next(int price) {
      while (price >= st.back().second) {
        st.pop_back();
      }
      int res = ++cur_day - st.back().first;
      st.emplace_back(cur_day, price);
      return res;
    }
  };

  // leetcode1124 表现良好的最长时间段
  int longestWPI(vector<int>& hours) {
    int n = hours.size(), res = 0;  //, s[n + 1];
    stack<int> st;
    vector<int> s(n + 1);
    st.push(0);
    s[0] = 0;
    for (int j = 1; j <= n; j++) {
      s[j] = s[j - 1] + (hours[j - 1] > 8 ? 1 : -1);
      if (s[j] < s[st.top()]) st.push(j);
    }
    for (int i = n; i > 0; i--) {
      while (!st.empty() && s[i] > s[st.top()]) {
        res = max(res, i - st.top());  // [栈顶, i)
        st.pop();
      }
    }
    return res;
  }
  // leetcode456 一三二模式
  bool find132pattern(vector<int>& nums) {
    // 增加一个arr_min数组,保存数组之前的最小值
    int n = nums.size();
    if (n < 3) return false;
    vector<int> arr_min(n);
    arr_min[0] = nums[0];
    for (int i = 1; i < n; i++) {
      arr_min[i] = min(arr_min[i - 1], nums[i]);
    }
    vector<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int x = nums[i];
      // 保证 2 > 1
      while (!st.empty() && st.back() <= arr_min[i]) {
        st.pop_back();
      }
      // 保证 3 > 2
      if (!st.empty() && x > st.back()) {
        return true;
      }
      st.emplace_back(x);
    }
    return false;
  }
  // leetcode2866 美丽塔II
  long long maximumSumOfHeights(vector<int>& a) {
    // 前后缀 + 单调栈
    int n = a.size();
    vector<long long> suf(n + 1, 0);
    stack<int> st;
    st.push(n);
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      while (st.size() > 1 && x <= a[st.top()]) {
        int j = st.top();
        st.pop();
        sum -= (long long)a[j] * (st.top() - j);
      }
      sum += (long long)x * (st.top() - i);
      suf[i] = sum;
      st.push(i);
    }

    st = stack<int>();
    st.push(-1);
    long long res = sum;
    long long pre = 0;
    for (int i = 0; i < n; i++) {
      int x = a[i];
      while (st.size() > 1 && x <= a[st.top()]) {
        int j = st.top();
        st.pop();
        pre -= (long long)a[j] * (j - st.top());
      }
      pre += (long long)x * (i - st.top());
      res = max(res, pre + suf[i + 1]);
      st.push(i);
    }
    return res;
  }
};

}  // namespace myleet

#endif