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

int getDepth(TreeNode* root) {
  if (!root) return 0;
  return 1 + std::max(getDepth(root->left), getDepth(root->right));
}

// leetcode110 平衡二叉树
bool LeetBTree::isBalanced(TreeNode* root) {
  // resolve 20191110
  // dfs
  if (NULL == root) return true;
  if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
  return isBalanced(root->left) && isBalanced(root->right);
}

// leetcode111 二叉树的最小深度
int LeetBTree::minDepth(TreeNode* root) {
  // resolve 20191110
  // dfs 递归
  // 要考虑根节点为空、根节点不为空左右子树都为空、左右节点其中一个为空的情况
  if (!root) return 0;
  if (NULL == root->left && NULL == root->right) return 1;
  if (NULL == root->left)
    return minDepth(root->right) + 1;
  else if (NULL == root->right)
    return minDepth(root->left) + 1;
  else
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

// leetcode112 路经总和
bool LeetBTree::hasPathSum(TreeNode* root, int targetSum) {
  // resolve 20231106
  // dfs 递归
  if (!root) return false;
  if (root->val == targetSum && !root->left && !root->right) return true;
  targetSum -= root->val;
  return hasPathSum(root->left, targetSum) ||
         hasPathSum(root->right, targetSum);
}

// leetcode226 翻转二叉树
TreeNode* LeetBTree::invertTree(TreeNode* root) {
  // resolve 20200709
  // dfs 递归
  if (NULL == root) return root;
  TreeNode* r = root->right;
  root->right = invertTree(root->left);
  root->left = invertTree(r);
  return root;
}

// leetcode257 二叉树的所有路径
std::vector<std::string> LeetBTree::binaryTreePaths(TreeNode* root) {
  // resolve 20231106
  // dfs
  std::vector<std::string> ans;
  std::function<void(TreeNode*, std::string path)> dfs = [&](TreeNode* cur,
                                                             std::string path) {
    path += std::to_string(cur->val);
    //遇到叶子节点
    if (cur->left == NULL && cur->right == NULL) {
      ans.push_back(std::string(path));
      return;
    }

    if (cur->left) {
      dfs(cur->left, path + "->");
    }
    if (cur->right) {
      dfs(cur->right, path + "->");
    }
  };

  dfs(root, "");

  return ans;
}

// leetcode404 左叶子之和
int LeetBTree::sumOfLeftLeaves(TreeNode* root) {
  if (!root) return 0;
  int res = 0;
  if (root->left && !root->left->left && !root->left->right) {
    res += root->left->val;
  }

  res += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

  return res;
}

std::unordered_map<int, int> count501;
int len_max501 = INT_MIN;
void dfs501(TreeNode* root, std::vector<int>& res) {
  if (!root) return;
  dfs501(root->left, res);
  res.emplace_back(root->val);
  {
    count501[root->val]++;
    if (count501[root->val] > len_max501) {
      len_max501 = count501[root->val];
    }
  }
  dfs501(root->right, res);
}

// leetcode501 二叉树中的众数
std::vector<int> LeetBTree::findMode(TreeNode* root) {
  // resolve 20231106
  // 中序遍历+哈希
  std::vector<int> num;
  dfs501(root, num);

  std::vector<int> res;
  for (std::pair<int, int> k : count501) {
    if (len_max501 == k.second) {
      res.emplace_back(k.first);
    }
  }

  return res;
}

int cut_min530 = INT_MAX;
int cur530 = INT_MAX;
void dfs530(TreeNode* root, std::vector<int>& nums) {
  if (!root) return;
  dfs530(root->left, nums);
  nums.emplace_back(root->val);
  {
    if (std::abs(root->val - cur530) < cut_min530) {
      cut_min530 = std::abs(root->val - cur530);
    }
    cur530 = root->val;
  }
  dfs530(root->right, nums);
}

// leetcode530 二叉搜索树最小绝对差值
int LeetBTree::getMinimumDifference(TreeNode* root) {
  // resolve 20231106
  // 中序遍历+全局记录最小差值
  std::vector<int> nums;
  dfs530(root, nums);
  return cut_min530;
}

int max543 = 0;
int dfs543(TreeNode* root) {
  if (!root->left && !root->right) {
    return 0;
  }

  int left = !root->left ? 0 : 1 + dfs543(root->left);
  int right = !root->right ? 0 : 1 + dfs543(root->right);

  max543 = std::max(max543, left + right);
  return std::max(left, right);
}

// leetcode543 二叉树的直径
int LeetBTree::diameterOfBinaryTree(TreeNode* root) {
  // resolve 20231106
  // 回溯 dfs 全局记录最大值
  if (!root) return 0;
  dfs543(root);
  return max543;
}

int max124 = INT_MIN;
int dfs124(TreeNode* root) {
  if (!root) {
    return 0;
  }

  int left = std::max(0, dfs124(root->left));
  int right = std::max(0, dfs124(root->right));

  max124 = std::max(max124, left + right + root->val);
  return std::max(left, right) + root->val;
}

// leetcode124 二叉树的最大路径和
int LeetBTree::maxPathSum(TreeNode* root) {
  // resolve 20231106
  // 回溯 dfs 全局记录最大值
  if (!root) return 0;
  dfs124(root);
  return max124;
}

int max687 = 0;
int dfs687(TreeNode* root) {
  if (!root->left && !root->right) {
    return 0;
  }

  int left = !root->left ? 0 : 1 + dfs687(root->left);
  int right = !root->right ? 0 : 1 + dfs687(root->right);

  if (left > 0 && root->left->val != root->val) {
    left = 0;
  }
  if (right > 0 && root->right->val != root->val) {
    right = 0;
  }

  max687 = std::max(max687, left + right);
  return std::max(left, right);
}

// leetcode687 最长同值路径
int LeetBTree::longestUnivaluePath(TreeNode* root) {
  // resolve 20231106
  // 回溯 dfs 全局记录最大值并判断同值
  if (!root) return 0;
  dfs687(root);
  return max687;
}

// leetcode116 填充每个节点的下一个右侧节点指针
// leetcode117 填充每个节点的下一个右侧节点指针II
Node* LeetBTree::connect(Node* root) {
  // ans 20231121
  // 两题同解
  // 递归遍历，然后把每层的最左侧的节点加到pre里面,depth等于pre的元素个数的时候说明现
  // 在是本层的最左侧节点，把它添加到pre中（很巧妙），之后动态的改变pre的节点
  std::vector<Node*> pre;
  std::function<void(Node*, int)> dfs = [&](Node* node, int depth) {
    // 边界
    if (node == nullptr) return;
    if (depth == pre.size()) {
      // node是本层最左侧节点
      pre.emplace_back(node);
    } else {
      // pre[depth]是node左边的节点
      pre[depth]->next = node;
      pre[depth] = node;
    }
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  };

  dfs(root, 0);
  return root;
}

long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
  int cnt1 = 0;
  int cnt2 = 0;
  int sum1 = 0;
  int sum2 = 0;
  for (auto& n : nums1) {
    if (0 == n) {
      sum1++;
      cnt1++;
    } else {
      sum1 += n;
    }
  }
  for (auto& n : nums2) {
    if (0 == n) {
      sum2++;
      cnt2++;
    } else {
      sum2 += n;
    }
  }

  if (sum1 > sum2) {
    return cnt2 > 0 ? sum1 : -1;
  } else if (sum1 < sum2) {
    return cnt1 > 0 ? sum2 : -1;
  } else {
    return sum1;
  }

  // return std::max(sum1, sum2);
  // int diff = sum1 - sum2;
}

}  // namespace myleet