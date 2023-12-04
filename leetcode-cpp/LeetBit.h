#ifndef __LEET_BIT_H__
#define __LEET_BIT_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetBit {
 public:
  LeetBit() {}
  ~LeetBit() {}

 public:
  // leetcode2917 找出数组中的 K-or 值
  static int findKOr(std::vector<int>& nums, int k);
  // leetcode2520 统计能整除数字的位数
  static int countDigits(int num);
  // 421. 数组中两个数的最大异或值
  int findMaximumXOR(vector<int>& nums);

  // leetcode1038 从二叉搜索树到更大和树
  static TreeNode* bstToGst(TreeNode* root) {
    int s = 0;
    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (nullptr == node) return;
      dfs(node->right);
      s += node->val;
      node->val = s;
      dfs(node->left);
    };
    dfs(root);
    return root;
  }
};

}  // namespace myleet

#endif