#ifndef __LEET_DFS_H__
#define __LEET_DFS_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetDFS {
 public:
  LeetDFS() {}
  ~LeetDFS() {}

 public:
  // leetcode94 中序遍历二叉树：先遍历左子树，再处理根节点，最后处理右子树
  static std::vector<int> inorderTraversal(TreeNode* root);
  // leetcode144 前序遍历二叉树：处理根节点，遍历左子树，最后处理右子树
  static std::vector<int> preorderTraversal(TreeNode* root);
  // leetcode145 后序遍历二叉树：遍历左子树，处理右子树，最后处理根节点
  static std::vector<int> postorderTraversal(TreeNode* root);
  // leetcode17 电话号码的字母组合
  static std::vector<std::string> letterCombinations(std::string digits);
  // leetcode78 子集
  static std::vector<std::vector<int>> subsets(std::vector<int>& nums);
  // leetcode131 分割回文串
  static std::vector<std::vector<std::string>> partition(std::string s);
  // leetcode77 组合
  static std::vector<std::vector<int>> combine(int n, int k);
  // leetcode216 组合总和III
  static std::vector<std::vector<int>> combinationSum3(int k, int n);
  // leetcode22 括号生成
  static std::vector<std::string> generateParenthesis(int n);
  // leetcode401 二进制手表
  static std::vector<std::string> readBinaryWatch(int t);
  // leetcode1863 找出所有子集的异或总和再求和
  static int subsetXORSum(std::vector<int>& nums);
  // LCP51 烹饪料理
  static int perfectMenu(std::vector<int>& materials,
                         std::vector<std::vector<int>>& cookbooks,
                         std::vector<std::vector<int>>& attribute, int limit);
  // leetcode46 全排列
  static std::vector<std::vector<int>> permute(std::vector<int>& nums);
  // leetcode51 N皇后
  static std::vector<std::vector<std::string>> solveNQueens(int n);
  // leetcode494 目标和
  static int findTargetSumWays(std::vector<int>& nums, int target);
  // leetcode1143 最长公共子序列
  static int longestCommonSubsequence(std::string s, std::string t);
  // leetcode1143 最长公共子序列
  static int minDistance(std::string word1, std::string word2);
  // leetcode300 最长递增子序列
  static int lengthOfLIS(std::vector<int>& nums);
  // leetcode516 最长回文子序列
  static int longestPalindromeSubseq(std::string s);
  // leetcode1039 多边形三角剖分的最低得分
  static int minScoreTriangulation(std::vector<int>& v);
  // leetcode1334 阈值距离内邻居最少的城市
  static int findTheCity(int n, std::vector<std::vector<int>>& edges,
                         int distanceThreshold);
  // leetcode2919 使数组变美的最小增量运算数
  static long long minIncrementOperations(std::vector<int>& nums, int k);
  // leetcode2008 出租车的最大盈利
  static long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto& r : rides) {
      int s = r[0], e = r[1], t = r[2];
      g[e].emplace_back(s, e - s + t);
    }
    vector<long long> cache(n + 1, -1);
    function<long long(int)> dfs = [&](int i) -> long long {
      if (1 == i) {
        return 0;
      }
      auto& res = cache[i];
      if (-1 != res) return res;
      res = dfs(i - 1);
      for (auto& [s, r] : g[i]) {
        res = max(res, dfs(s) + r);
      }
      return res;
    };
    return dfs(n);
  }
  // leetcode2316 统计无向图中无法互相到达点对数
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1];
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
    vector<int> vis(n);
    function<int(int)> dfs = [&](int x) -> int {
      vis[x] = true;
      int size = 1;
      for (int y : g[x]) {
        if (!vis[y]) size += dfs(y);
      }
      return size;
    };

    long long res = 0;
    for (int i = 0, total = 0; i < n; i++) {
      if (!vis[i]) {
        int size = dfs(i);
        res += (long)size * total;
        total += size;
      }
    }
    return res;
  }
  // leetcode2415 反转二叉树的奇数层
  TreeNode* reverseOddLevels(TreeNode* root) {
    function<void(TreeNode*, TreeNode*, bool)> dfs =
        [&](TreeNode* n1, TreeNode* n2, bool re) {
          if (!n1) return;
          if (re) {
            int a = n1->val;
            n1->val = n2->val;
            n2->val = a;
          }
          re = !re;
          dfs(n1->left, n2->right, re);
          dfs(n1->right, n2->left, re);
        };
    dfs(root->left, root->right, true);
    return root;
  }
};

}  // namespace myleet

#endif