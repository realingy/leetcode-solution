#ifndef __LEET_STACK_H__
#define __LEET_STACK_H__

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
};

}  // namespace myleet

#endif