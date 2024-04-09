#ifndef __LEET_BTREE_H__
#define __LEET_BTREE_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// 多叉树
class MNode {
 public:
  int val;
  vector<MNode*> children;
  MNode() {}
  MNode(int _val) { val = _val; }
  MNode(int _val, vector<MNode*> _children) {
    val = _val;
    children = _children;
  }
};

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
  // leetcode543 二叉树的直径
  int diameterOfBinaryTree(TreeNode* root);
  // leetcode124 二叉树的最大路径和
  int maxPathSum(TreeNode* root);
  // leetcode687 最长同值路径
  int longestUnivaluePath(TreeNode* root);
  // leetcode116 填充每个节点的下一个右侧节点指针
  static Node* connect(Node* root);
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

  // leetcode559 N叉树的最大深度
  int maxDepth(MNode* root) {
    std::function<int(MNode*)> dfs = [&](MNode* node) -> int {
      if (nullptr == node) {
        return 0;
      }
      int depth = 0;
      for (MNode* c : node->children) {
        depth = max(depth, dfs(c));
      }
      depth++;
      return depth;
    };
    return dfs(root);
  }

  // leetcode563 二叉树的坡度
  int findTilt(TreeNode* root) {
    int res = 0;
    std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
      if (nullptr == node) return 0;
      int l = dfs(node->left);
      int r = dfs(node->right);
      res += abs(l - r);
      return node->val + l + r;
    };
    dfs(root);
    return res;
  }

  bool check(TreeNode* o, TreeNode* t) {
    if (!o && !t) {
      return true;
    }
    if ((o && !t) || (!o && t) || (o->val != t->val)) {
      return false;
    }
    return check(o->left, t->left) && check(o->right, t->right);
  }
  // leetcode572 另一棵树的子树
  bool isSubtree(TreeNode* s, TreeNode* t) {
    std::function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* n1,
                                                        TreeNode* n2) {
      if (!n1) return false;
      return check(n1, n2) || dfs(n1->left, n2) || dfs(n1->right, n2);
    };
    return dfs(s, t);
  }
  // leetcode222 完全二叉树的节点个数
  int countNodes(TreeNode* root) {
    if (nullptr == root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  // leetcode1026 节点与其祖先之间的最大差值
  int maxAncestorDiff(TreeNode* root) {
    int ans = 0;
    std::function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int mn,
                                                       int mx) {
      if (!node) return;
      mn = std::min(node->val, mn);
      mx = std::max(node->val, mx);
      ans = std::max(std::max(node->val - mn, ans), mx - node->val);
      dfs(node->left, mn, mx);
      dfs(node->right, mn, mx);
    };
    dfs(root, root->val, root->val);
    return ans;
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      g[e[1]].emplace_back(e[0]);
    }

    vector<vector<int>> ans(n);
    vector<int> vis(n);
    std::function<void(int)> dfs = [&](int x) {
      vis[x] = true;
      for (int y : g[x]) {
        if (!vis[y]) {
          dfs(y);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      vis = std::vector<int>(n, false);
      dfs(i);
      vis[i] = false;
      for (int j = 0; j < n; j++) {
        if (vis[j]) {
          ans[i].push_back(j);
        }
      }
    }
    return ans;
  }
};

}  // namespace myleet

#endif