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
    // 边界返回
    return;
  }
  std::string cur = phone[src[i] - '0'];
  for (char ch : cur) {
    path17 += ch;
    dfs17(src, i + 1);
    path17.pop_back();  // 回溯
  }
}

// leetcode131 <==> leetcode78 <==> leetcode17
// leetcode17 电话号码的字母组合
std::vector<std::string> LeetDFS::letterCombinations(std::string digits) {
  // ans 20231112
  // 时间复杂度O(n*4^n)
  res17 = std::vector<std::string>();
  path17 = "";
  int n = (int)digits.size();
  if (!n) return {};

  dfs17(digits, 0);

  return res17;
}

std::vector<std::vector<int>> res78;
std::vector<int> temp78;
void dfs78(std::vector<int>& nums, int i) {
  if (i == nums.size()) {
    res78.emplace_back(std::vector<int>(temp78));
    return;
  }

  {
    // 两种情况，第一种，考虑当前数
    temp78.emplace_back(nums[i]);
    dfs78(nums, i + 1);
    temp78.pop_back();
  }
  {
    // 两种情况，第二种，不考虑当前数
    dfs78(nums, i + 1);
  }
}

// leetcode131 <==> leetcode78 <==> leetcode17
// leetcode78 子集
std::vector<std::vector<int>> LeetDFS::subsets(std::vector<int>& nums) {
  // resolve 20231112
  // 时间复杂度O(n*2^n): 拷贝temp用时间n，考虑两种情况需要2^n
  int n = (int)nums.size();
  if (!n) return {};

  dfs78(nums, 0);

  return res78;
}

bool isPalindrome(std::string& s, int left, int right) {
  while (left < right)
    if (s[left++] != s[right--]) return false;
  return true;
}

// leetcode131 <==> leetcode78 <==> leetcode17
// leetcode131 分割回文串
std::vector<std::vector<std::string>> LeetDFS::partition(std::string s) {
  std::vector<std::vector<std::string>> ans;
  std::vector<std::string> path;

  int n = s.length();

  // start 表示当前这段回文子串的开始位置
  std::function<void(int, int)> dfs = [&](int i, int start) {
    if (i == n) {
      ans.emplace_back(path);
      return;
    }

    // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
    if (i < n - 1) dfs(i + 1, start);
    // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
    if (isPalindrome(s, start, i)) {
      path.push_back(s.substr(start, i - start + 1));
      dfs(i + 1, i + 1);  // 下一个子串从 i+1 开始
      path.pop_back();    // 恢复现场
    }
  };

  dfs(0, 0);
  return ans;
}

}  // namespace myleet