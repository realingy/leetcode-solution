#ifndef __LEET_BTREE_H__
#define __LEET_BTREE_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetBTree {
 public:
  LeetBTree() {}
  ~LeetBTree() {}

 public:
  // leetcode100 相同的树
  static bool isSameTree(TreeNode* p, TreeNode* q);
  // leetcode101 对称的树
  static bool isSymmetric(TreeNode* root);
  // leetcode106 树的最大深度
  int maxDepth(TreeNode* root);
  // leetcode108 将有序数组转换为二叉搜索树
  TreeNode* sortedArrayToBST(std::vector<int>& nums);
  // leetcode110 平衡二叉树
  bool isBalanced(TreeNode* root);
  // leetcode111 二叉树的最小深度
  int minDepth(TreeNode* root);
  // leetcode112 路经总和
  bool hasPathSum(TreeNode* root, int targetSum);
  // leetcode226 翻转二叉树
  TreeNode* invertTree(TreeNode* root);
  // leetcode257 二叉树的所有路径
  std::vector<std::string> binaryTreePaths(TreeNode* root);
  // leetcode404 左叶子之和
  int sumOfLeftLeaves(TreeNode* root);
  // leetcode501 二叉树中的众数
  std::vector<int> findMode(TreeNode* root);
  // leetcode530 二叉搜索树最小绝对差值
  int getMinimumDifference(TreeNode* root);
};

}  // namespace myleet

#endif