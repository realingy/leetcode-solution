#include "LeetDP.h"

#include <algorithm>
#include <iostream>

namespace myleet {

int LeetDP::climbStairs(int n) {
  // review 20231103
  // 动态规划，斐波那契
  int a = 1, b = 1, sum;
  for (int i = 0; i < n - 1; i++) {
    sum = a + b;
    a = b;
    b = sum;
  }
  return b;
}

// leetcode118 杨辉三角
std::vector<std::vector<int>> LeetDP::generateYanghui(int numRows) {
  std::vector<std::vector<int>> res(numRows);
  if (numRows >= 1) res[0].emplace_back(1);
  if (numRows >= 2) {
    res[1].emplace_back(1);
    res[1].emplace_back(1);
  }
  for (int i = 2; i < numRows; i++) {
    res[i].emplace_back(1);
    for (int j = 1; j <= i - 1; j++) {
      res[i].emplace_back(res[i - 1][j - 1] + res[i - 1][j]);
    }
    res[i].emplace_back(1);
  }

  return res;
}

// leetcode121 买卖股票最大利润
int LeetDP::maxProfit(std::vector<int>& prices) {
  // resolve 20231104
  // DP,一次遍历，记录最低售价（相等也不重新记录，必须小于），并判断最高利润
  int min = INT_MAX;
  int res = 0;

  for (int p : prices) {
    if (p < min) {
      min = p;
    } else if (p - min > res) {
      res = p - min;
    }
  }

  return res;
}

// leetcode338 比特位计数
std::vector<int> LeetDP::countBits(int n) {
  // resolve 20231104
  // 位运算
  // 偶数相当于被某个更小的数乘2，在二进制运算中，乘2就是左移一位，也就是在低位多加1个0，dp
  // [i] = dp[i / 2]
  // 奇数由不大于该数的偶数+1得到，偶数+1在二进制位上会发生什么？会在低位多加1个1，那样就说明dp[i]
  // = dp[i-1] + 1，当然也可以写成dp[i] = dp[i / 2] + 1
  std::vector<int> res(n + 1);

  for (int i = 0; i <= n; i++) {
    if (0 == i % 2) {
      res[i] = res[i / 2];
    } else {
      res[i] = res[i / 2] + 1;
    }
  }

  return res;
}

// leetcode392 判断子序列
bool LeetDP::isSubsequence(std::string s, std::string t) {
#if 0
  // resolve 20231031
  // 暴力匹配
  int pt = -1;
  for (int i = 0; i < s.size(); i++) {
    char cur = s[i];
    bool find = false;
    for (int j = 0; j < t.size(); j++) {
      if (cur == t[j]) {
        if (j > pt) {
          pt = j;
          find = true;
          break;
        } else {
          continue;
        }
      }
    }
    if (!find) return false;
  }
  return true;
#else
  // resolve 20231104
  // 双指针
  int i = 0;
  int j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }

  return i == s.size();
#endif
}

// leetcode509 斐波那契数
int LeetDP::fib(int n) {
  // resolve 20231104
  // 动态规划
  int res = 0;
  if (0 == n) return 0;
  if (1 == n) return 1;

  int a = 0, b = 1;
  int i = 2;
  while (i++ <= n) {
    res = a + b;
    a = b;
    b = res;
  }

  return res;
}

// leetcode746 使用最小花费爬楼梯
int LeetDP::minCostClimbingStairs(std::vector<int>& cost) {
  // resolve 20231104
  // DP,动态规划问题，每一步都判断一次跨一阶还是两阶
  // 注意当阶数小于2的时候可以一次跨上去
  // 注意dp[0]和dp[1]都等于0，dp[3]开始统计
  // 注意这里动态规划数组长度必须比cost大一
  int n = (int)cost.size();
  std::vector<int> res(n + 1);
  if (n < 2) return 0;
  res[0] = 0;
  res[1] = 0;
  for (int i = 2; i <= n; i++) {
    res[i] = std::min(res[i - 1] + cost[i - 1], res[i - 2] + cost[i - 2]);
  }

  return res[n];
}

// leetcode1025 除数博弈
bool LeetDP::divisorGame(int n) { return 0 == n % 2; }

// leetcode1137 泰波那契数
int LeetDP::tribonacci(int n) {
  // resolve 20231104
  // DP
  int res = 0;
  if (0 == n) return 0;
  if (1 == n) return 1;
  if (2 == n) return 1;

  int a = 0, b = 1, c = 1;
  int i = 3;
  while (i++ <= n) {
    res = a + b + c;
    a = b;
    b = c;
    c = res;
  }

  return res;
}

// leetcode1646 生成特殊数组并返回最大值
// 给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：
// nums[0] = 0
// nums[1] = 1
// 当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
// 当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
int getMaximumGenerated(int n) {
  int res = INT_MIN;
  if (0 == n) return 0;
  if (1 == n) return 1;
  std::vector<int> arr(n + 1);
  arr[0] = 0;
  arr[1] = 1;
  int i = 2;
  while (i <= n) {
    if (0 == i % 2) {
      arr[i] = arr[i / 2];
    } else {
      arr[i] = arr[(i - 1) / 2] + arr[(i + 1) / 2];
    }

    if (arr[i] > res) {
      res = arr[i];
    }
    i++;
  }

  return res;
}

}  // namespace myleet