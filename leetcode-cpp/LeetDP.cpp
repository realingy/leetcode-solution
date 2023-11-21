#include "LeetDP.h"

#include <algorithm>
#include <iostream>

namespace myleet {

int LeetDP::baseDP(std::vector<int> nums) {
  // 动态规划基本思想: 相邻的数据不能连续选，最后得到最大的和(可以跳过多个)
  int n = (int)nums.size();
  std::vector<int> dp(n);

  dp[0] = nums[0];
  dp[1] = std::max(nums[0], nums[1]);
  for (int i = 2; i < n; ++i) {
    dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
  }

  return dp[n - 1];
}

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
int LeetDP::getMaximumGenerated(int n) {
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

// LCP07 传递信息
int LeetDP::numWays(int n, std::vector<std::vector<int>>& relation, int k) {
  // ans 20231105
  // DP
  std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n));
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (auto& edge : relation) {
      int src = edge[0], dst = edge[1];
      dp[i + 1][dst] += dp[i][src];
    }
  }
  return dp[k][n - 1];
}

// leetcode122 买卖股票的最佳时机II
int LeetDP::maxProfit2(std::vector<int>& prices) {
  // resolve 20231108
  // 因为不限制交易次数，我们在第i天买入，如果发现i+1天比i高，那么就可以累加到利润里面
  if (prices.size() < 2) return 0;

  int res = 0;
  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] - prices[i - 1] > 0) {
      res += prices[i] - prices[i - 1];
    }
  }

  return res;
}

// leetcode50 Pow(x, n)
double LeetDP::myPow(double x, int n) {
  // ans 20231109
  // 递归
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n == -1) return 1 / x;
  double half = myPow(x, n / 2);
  double rest = myPow(x, n % 2);
  return rest * half * half;
}

// leetcode53 最大子数组和
int LeetDP::maxSubArray(std::vector<int>& nums) {
  // resolve 20231109
#if 0
  // 动态规划+一次遍历，记录最大值
  int pre = 0;
  int res = nums[0];
  for (const auto& x : nums) {
    pre = std::max(pre + x, x);
    res = std::max(res, pre);
  }

  return res;

  /*
  // 另一种动态规划，前边的值大于0，则加到本元素上， 原理一样
  int n = (int)nums.size();
  std::vector<int> dp(n);
  dp[0] = nums[0];
  int res = nums[0];
  for (int i = 1; i < n; ++i) {
    if (dp[i - 1] > 0) {
      dp[i] = dp[i - 1] + nums[i];
    } else {
      dp[i] = nums[i];
    }
    res = std::max(dp[i], res);
  }

  return res;
  */
#else
  // ans
  // 20231121，将子数组的元素和转换成前缀和之差，记录最小前缀和，同时记录最大前缀和
  int ans = INT_MIN;
  int pre_sum_min = 0;
  int pre_sum = 0;
  for (int x : nums) {
    pre_sum += x;                                // 当前的前缀和
    ans = std::max(ans, pre_sum - pre_sum_min);  // 减去前缀和的最小值
    pre_sum_min = std::min(pre_sum_min, pre_sum);  // 维护前缀和的最小值
  }
  return ans;

#endif
}

// leetcode55 跳跃游戏
bool LeetDP::canJump(std::vector<int>& nums) {
#if 0
  // resolve 20231109
  // 动态规划,记录每个位置所剩最大步数
  int n = (int)nums.size();
  std::vector<int> dp(n);  //当前位置剩下的最大步数
  dp[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = std::max(nums[i - 1] - 1, dp[i - 1] - 1);
    if (dp[i] < 0) return false;
  }

  return true;
#else
  int n = (int)nums.size();
  int cur = nums[0];
  for (int i = 1; i < n; ++i) {
    cur = std::max(nums[i - 1] - 1, cur - 1);
    if (cur < 0) return false;
  }
  return true;
#endif
}

// std::string LeetDP::getPermutation(int n, int k) { std::string res; }

// leetcode62 不同路径
int LeetDP::uniquePaths(int m, int n) {
  // resolve 20231109
  // DP
  if (1 == m || 1 == n) return 1;
  int res = 0;
  std::vector<std::vector<int>> dp(m, std::vector<int>(n));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    dp[i][0] = 1;
  }
  for (int j = 0; j < n; j++) {
    dp[0][j] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];
}

// leetcode63 不同路径 II
int LeetDP::uniquePathsWithObstacles(std::vector<std::vector<int>>& obs) {
  int m = (int)obs.size();
  int n = (int)obs[0].size();
  if (1 == m && 1 == n) {
    return !obs[0][0] ? 1 : 0;
  }

  if (1 == m) {
    for (int i = 0; i < n; i++) {
      if (obs[0][i] > 0) return 0;
    }
    return 1;
  }
  if (1 == n) {
    for (int i = 0; i < m; i++) {
      if (obs[i][0] > 0) return 0;
    }
    return 1;
  }

  std::vector<std::vector<int>> dp(m, std::vector<int>(n));
  dp[0][0] = !obs[0][0] ? 1 : 0;
  for (int i = 1; i < m; i++) {
    if (0 == dp[i - 1][0])
      dp[i][0] = 0;
    else
      dp[i][0] = !obs[i][0] ? 1 : 0;
  }
  for (int j = 1; j < n; j++) {
    if (!dp[0][j - 1])
      dp[0][j] = 0;
    else
      dp[0][j] = !obs[0][j] ? 1 : 0;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = !obs[i][j] ? (dp[i - 1][j] + dp[i][j - 1]) : 0;
    }
  }

  return dp[m - 1][n - 1];
}

// leetcode64 最小路径和
int LeetDP::minPathSum(std::vector<std::vector<int>>& grid) {
  int m = (int)grid.size();
  int n = (int)grid[0].size();
  int res = 0;
  if (1 == m && 1 == n) {
    return grid[0][0];
  } else if (1 == m) {
    res = 0;
    for (int i = 0; i < n; i++) {
      res += grid[0][i];
    }
    return res;
  } else if (1 == n) {
    res = 0;
    for (int i = 0; i < m; i++) {
      res += grid[i][0];
    }
    return res;
  }

  std::vector<std::vector<int>> dp(m, std::vector<int>(n));
  dp[0][0] = grid[0][0];
  for (int i = 1; i < m; i++) {
    dp[i][0] += dp[i - 1][0] + grid[i][0];
  }
  for (int i = 1; i < n; i++) {
    dp[0][i] += dp[0][i - 1] + grid[0][i];
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }

  return dp[m - 1][n - 1];
}

// leetcode198 打家劫舍
int LeetDP::rob(std::vector<int>& nums) {
#if 0
  // resolve 20231115
  // DP
  int n = nums.size();
  if (n < 2) return nums[0];
  if (n < 3) return std::max(nums[0], nums[1]);
  std::vector<int> dp(n, 0);

  dp[0] = nums[0];
  dp[1] = std::max(nums[0], nums[1]);

  for (int i = 2; i < n; i++) {
    dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
  }

  return dp[n - 1];
#else
  // ans 20231116
  // 优化空间复杂度
  int n = (int)nums.size();
  if (n < 2) return nums[0];
  if (n < 3) return std::max(nums[0], nums[1]);

  int a = nums[0];
  int b = std::max(nums[0], nums[1]);

  int res = 0;
  for (int i = 2; i < n; i++) {
    res = std::max(b, a + nums[i]);
    a = b;
    b = res;
  }

  return res;
#endif
}

}  // namespace myleet