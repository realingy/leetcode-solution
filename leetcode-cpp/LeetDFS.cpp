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

// leetcode77 组合
std::vector<std::vector<int>> LeetDFS::combine(int n, int k) {
  // resolve 20231113
  // 回溯，在子集的基础上进行优化
  // 时间复杂度O(k*Cnk),满足要求的叶子的个数乘以叶子到根的路径长度，空间复杂度为O(k)
  std::vector<std::vector<int>> res;
  std::vector<int> path;
  std::function<void(int)> dfs = [&](int i) {
    // 剪枝，这里就是在子集的基础上可以优化的地方
    if (k - path.size() > i) return;

    if (path.size() == k) {
      res.emplace_back(std::vector<int>(path));
    }

    int j = i;
    while (j > 0) {
      path.emplace_back(j);
      dfs(j - 1);
      path.pop_back();
      --j;
    }
  };

  dfs(n);

  return res;
}

// leetcode216 组合总和III
std::vector<std::vector<int>> LeetDFS::combinationSum3(int k, int n) {
#if 0
  // resolve 20231113
  // 回溯，在子集的基础上进行优化,同时再加一个约束条件就是path的和等于n
  // 时间复杂度O(k*Cnk),满足要求的叶子的个数乘以叶子到根的路径长度
  std::vector<std::vector<int>> res;
  std::vector<int> path;
  std::function<void(int)> dfs = [&](int i) {
    // 剪枝，这里就是在子集的基础上可以优化的地方
    if (k - path.size() > i) return;
    if (k == path.size()) {
      int sum = accumulate(path.begin(), path.end(), 0);
      if (n == sum) {
        res.emplace_back(path);
      }
    }

    int j = i;
    while (j > 0) {
      path.emplace_back(j);
      dfs(j - 1);
      path.pop_back();
      --j;
    }
  };

  dfs(9);

  return res;
#else
  // ans 20231114
  // 回溯，在子集的基础上进行优化,同时再加一个约束条件就是path的和等于n
  std::vector<std::vector<int>> res;
  std::vector<int> path;
  std::function<void(int, int)> dfs = [&](int i, int t) {
    // 剪枝，这里就是在子集的基础上可以优化的地方
    int d = k - path.size();
    if (d > i) return;
    if (t < 0 || t > ((2 * i - d + 1) / 2)) return;

    if (k == path.size()) {
      int sum = accumulate(path.begin(), path.end(), 0);
      if (n == sum) {
        res.emplace_back(path);
      }
    }

    int j = i;
    while (j > d) {
      path.emplace_back(j);
      dfs(j - 1, t - j);
      path.pop_back();
      --j;
    }
  };

  dfs(9, n);

  return res;

#endif
}

// leetcode22 括号生成
std::vector<std::string> LeetDFS::generateParenthesis(int n) {
  std::vector<std::string> res;
  std::string path(2 * n, 0);
  // t表示左括号"("的个数
  std::function<void(int, int)> dfs = [&](int i, int t) {
    if (i == 2 * n) {
      res.emplace_back(path);
    }

    // 一共可以填n个左括号，所以t小于n表示可以填左括号'('
    if (t < n) {
      path[i] = '(';
      dfs(i + 1, t + 1);
    }

    // i-t表示右括号的个数，当右括号的个数小于左括号的个数，可以填右括号')'
    if (i - t < t) {
      path[i] = ')';
      dfs(i + 1, t);
    }
  };

  dfs(0, 0);

  return res;
}

std::vector<std::string> removeInvalidParentheses(std::string s) {
  int left = 0;  /* 表示左括号最少删除的数量 */
  int right = 0; /* 表示右括号最少删除的数量 */
  for (auto& c : s) {
    if (c == '(') {
      left++;
    } else if (c == ')') {
      if (left <= 0) {
        right++;
      } else {
        left--;
      }
    }
  }

  std::cout << "left: " << left << "right: " << right << std::endl;

  std::vector<std::string> res;
  std::string path;
  int n = s.size();
  std::cout << "s: " << s << ", n: " << n << std::endl;
  std::unordered_set<std::string> set;
  std::function<void(int, int, int)> dfs = [&](int i, int l, int r) {
    // l表示左括号的个数，r表示右括号的个数
    if (n == i) {
      // std::cout << "l: " << l << ", r: " << r << std::endl;
      if (l == r && !set.count(path) && left <= 0) {
        res.emplace_back(std::string(path));
        set.insert(std::string(path));
      }
      return;
    }

    if ('(' != s[i] && ')' != s[i]) {
      path += s[i];
      dfs(i + 1, l, r);
    } else if ('(' == s[i]) {
      std::cout << "i: " << i << ": "
                << "l: " << l << ", r: " << r << ", right: " << right
                << ", left: " << left << std::endl;
      if (left <= 0) {
        path += '(';
        dfs(i + 1, l + 1, r);
        path.pop_back();
      } else {
        {
          path += '(';
          dfs(i + 1, l + 1, r);
          path.pop_back();
        }
        {
          left--;
          dfs(i + 1, l, r);
        }
      }
    } else if (')' == s[i]) {
      // std::cout << i << ": " << "l: " << l << ", r: " << r << ", right: " <<
      // right << std::endl; 右括号少的情况下，可以选择选或者不选
      if (l > r) {
        if (right > 0) {
          {
            right--;
            dfs(i + 1, l, r);
          }
          {
            path += ')';
            dfs(i + 1, l, r + 1);
            path.pop_back();
          }
        } else {
          // std::cout << i << "xxxxxx: " << std::endl;
          {
            path += ')';
            dfs(i + 1, l, r + 1);
            path.pop_back();
          }
        }
      } else {
        right--;
        // 右括号多的情况下，必然跳过
        dfs(i + 1, l, r);
      }
    }
  };

  dfs(0, 0, 0);

  return res.empty() ? std::vector<std::string>{""} : res;
}

}  // namespace myleet