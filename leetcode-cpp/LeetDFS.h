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
  std::vector<int> inorderTraversal(TreeNode* root);
  // leetcode144 前序遍历二叉树：处理根节点，遍历左子树，最后处理右子树
  std::vector<int> preorderTraversal(TreeNode* root);
  // leetcode145 后序遍历二叉树：遍历左子树，处理右子树，最后处理根节点
  std::vector<int> postorderTraversal(TreeNode* root);
};

}  // namespace myleet

#endif