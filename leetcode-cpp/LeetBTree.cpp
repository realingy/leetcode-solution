#include "LeetBTree.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode100 相同的树
bool LeetBTree::isSameTree(TreeNode* p, TreeNode* q) {
  // resolve 20231106
  // 递归
  if (!p && !q) return true;
  if (!p || !q) return false;
  if (p->val == q->val) {
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  return false;
}

bool helper(TreeNode* left, TreeNode* right) {
  if (!left && !right)
    return true;
  else if (!left && right || left && !right || left->val != right->val)
    return false;

  return helper(left->left, right->right) && helper(left->right, right->left);
}

// leetcode101 对称的树
bool LeetBTree::isSymmetric(TreeNode* root) {
  // resolve 20231106
  // 递归
  if (!root) return true;
  return helper(root->left, root->right);
}

// leetcode106 树的最大深度
int LeetBTree::maxDepth(TreeNode* root) {
  if (!root) return 0;
  return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* helper108(std::vector<int>& nums, int left, int right) {
  if (left > right) return NULL;
  int mid = (left + right) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = helper108(nums, left, mid - 1);
  root->right = helper108(nums, mid + 1, right);
  return root;
}

// leetcode108 将有序数组转换为二叉搜索树
TreeNode* LeetBTree::sortedArrayToBST(std::vector<int>& nums) {
  return helper108(nums, 0, nums.size() - 1);
}

}  // namespace myleet