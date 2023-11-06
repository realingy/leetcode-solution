#ifndef __LEET_DP_H__
#define __LEET_DP_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace myleet {

class LeetDP {
 public:
  LeetDP() {}
  ~LeetDP() {}

 public:
  // DP基本思想
  int baseDP(std::vector<int> nums);
  //
  static int climbStairs(int n);
  // leetcode118 杨辉三角
  static std::vector<std::vector<int>> generateYanghui(int numRows);
  // leetcode121 买卖股票最大利润
  static int maxProfit(std::vector<int>& prices);
  // leetcode338 比特位计数
  static std::vector<int> countBits(int n);
  // leetcode392 判断子序列
  static bool isSubsequence(std::string s, std::string t);
  // leetcode509 斐波那契数
  static int fib(int n);
  // leetcode746 使用最小花费爬楼梯
  static int minCostClimbingStairs(std::vector<int>& cost);
  // leetcode1025 除数博弈
  static bool divisorGame(int n);
  // leetcode1137 泰波那契数
  static int tribonacci(int n);
  // leetcode1646 生成特殊数组并返回最大值
  static int getMaximumGenerated(int n);
  // LCP07 传递信息
  static int numWays(int n, std::vector<std::vector<int>>& relation, int k);
};

}  // namespace myleet

#endif