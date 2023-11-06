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
};

}  // namespace myleet

#endif