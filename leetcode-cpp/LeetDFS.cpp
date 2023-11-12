#include "LeetDFS.h"

#include <algorithm>
#include <iostream>

namespace myleet {

void dfs94(TreeNode* root, std::vector<int>& res) {
  if (!root) return;
  dfs94(root->left, res);
  res.emplace_back(root->val);
  dfs94(root->right, res);
}

// leetcode94 中序遍历二叉树：先遍历左子树，再处理根节点，最后处理右子树
std::vector<int> LeetDFS::inorderTraversal(TreeNode* root) {
  std::vector<int> res;
  dfs94(root, res);
  return res;
}

void dfs144(TreeNode* root, std::vector<int>& res) {
  if (!root) return;
  res.emplace_back(root->val);
  dfs144(root->left, res);
  dfs144(root->right, res);
}

// leetcode144 前序遍历二叉树：处理根节点，遍历左子树，最后处理右子树
std::vector<int> LeetDFS::preorderTraversal(TreeNode* root) {
  std::vector<int> res;
  dfs144(root, res);
  return res;
}

void dfs145(TreeNode* root, std::vector<int>& res) {
  if (!root) return;
  dfs145(root->left, res);
  dfs145(root->right, res);
  res.emplace_back(root->val);
}

// leetcode145 后序遍历二叉树：遍历左子树，处理右子树，最后处理根节点
std::vector<int> LeetDFS::postorderTraversal(TreeNode* root) {
  std::vector<int> res;
  dfs145(root, res);
  return res;
}

std::string path17;
std::vector<std::string> res17;
std::string phone[10] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs17(const std::string& src, int i) {
  if (i == src.size()) {
    res17.emplace_back(path17);
    return;
  }

  int idx = src[i] - '0';
  std::string cur = phone[idx];
  for (char ch : cur) {
    path17 += ch;
    dfs17(src, i + 1);
    path17.pop_back();  // 回溯
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  res17 = std::vector<std::string>();
  path17 = "";
  int n = (int)digits.size();
  if (!n) return {};

  dfs17(digits, 0);

  return res17;
}

}  // namespace myleet