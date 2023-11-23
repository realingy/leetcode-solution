#ifndef __LEET_DFS_H__
#define __LEET_DFS_H__

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
  int longestCommonSubsequence(std::string s, std::string t);
  // leetcode1143 最长公共子序列
  int minDistance(std::string word1, std::string word2);
  // leetcode300 最长递增子序列
  int lengthOfLIS(std::vector<int>& nums);
  // leetcode516 最长回文子序列
  int longestPalindromeSubseq(std::string s);
  // leetcode1039 多边形三角剖分的最低得分
  int minScoreTriangulation(std::vector<int>& v);
  // leetcode1334 阈值距离内邻居最少的城市
  int findTheCity(int n, std::vector<std::vector<int>>& edges,
                  int distanceThreshold);
  // leetcode2919 使数组变美的最小增量运算数
  long long minIncrementOperations(std::vector<int>& nums, int k);
};

}  // namespace myleet

#endif