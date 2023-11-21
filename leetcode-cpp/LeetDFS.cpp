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
  // error 20231115
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

// leetcode401 二进制手表
std::vector<std::string> LeetDFS::readBinaryWatch(int t) {
  // resolve 20231115
  // 回溯 + 递归
  std::vector<std::string> res;
  std::function<void(int, int, int, int, int)> dfs = [&](int i, int h, int m,
                                                         int ch, int cm) {
    // 剪枝
    if (h > 11 || m > 59 || ch > 4 || cm > 6) return;
    if (i == t) {
      res.emplace_back(std::to_string(h) + ":" + ((m < 10) ? "0" : "") +
                       std::to_string(m));
      return;
    }

    dfs(i + 1, h | (1 << ch), m, ch + 1, cm);  // 选择当前小时位
    dfs(i, h, m, ch + 1, cm);                  // 不选择当前的小时位
    if (4 == ch) {
      dfs(i + 1, h, m | (1 << cm), ch, cm + 1);  // 选择当前分钟位
      dfs(i, h, m, ch, cm + 1);                  // 不选择当前的分钟位
    }
  };

  dfs(0, 0, 0, 0, 0);

  return res;
}

// leetcode1863 找出所有子集的异或总和再求和
int LeetDFS::subsetXORSum(std::vector<int>& nums) {
  int res = 0;
  int n = (int)nums.size();
  std::function<void(int, int)> dfs = [&](int i, int path) {
    if (i == n) {
      res += path;
    }

    dfs(i + 1, path ^ nums[i]);  // 选择当前位
    dfs(i + 1, path);            // 不选择当前位
  };

  dfs(0, 0);

  return res;
}

// LCP51 烹饪料理
int LeetDFS::perfectMenu(std::vector<int>& materials,
                         std::vector<std::vector<int>>& cookbooks,
                         std::vector<std::vector<int>>& attribute, int limit) {
  int res = -1;
  int n = (int)materials.size();
  int m = (int)cookbooks.size();
  std::function<void(int, int, int, std::vector<int>)> dfs =
      [&](int i, int x, int y, std::vector<int> used) {
        if (y >= limit) {
          res = std::max(res, x);
        }
        if (i == m) {
          return;
        }
        for (int j = 0; j < n; j++) {
          if (materials[j] - used[j] < cookbooks[i][j]) return;
        }

        {
          // 选择当前料理
          bool match = true;
          for (int j = 0; j < n; j++) {
            // 保证可以选
            if (materials[j] - used[j] < cookbooks[i][j]) {
              match = false;
              break;
            }
          }

          if (true == match) {
            for (int j = 0; j < n; j++) used[j] += cookbooks[i][j];
            dfs(i + 1, x + attribute[i][0], y + attribute[i][1], used);
            for (int j = 0; j < n; j++) used[j] -= cookbooks[i][j];
          }
        }
        {
          // 不选择当前料理
          dfs(i + 1, x, y, used);
        }
      };

  std::vector<int> used(n, 0);
  dfs(0, 0, 0, used);

  return res;
}

// leetcode46 <==> leetcode51
// leetcode46 全排列
std::vector<std::vector<int>> LeetDFS::permute(std::vector<int>& nums) {
  // resolve 20231115
  // 回溯问题
  std::vector<std::vector<int>> res;
  int n = (int)nums.size();
  std::vector<int> path(n, 0);
  std::vector<int> on_path(n, 0);
  std::function<void(int)> dfs = [&](int i) {
    if (n == i) {
      res.emplace_back(std::vector<int>(path));
      return;
    }
    // 全排列，遍历nums所有元素，遍历到的放到on_path中
    for (int k = 0; k < n; k++) {
      if (0 == on_path[k]) {
        on_path[k] = 1;
        path[i] = nums[k];
        dfs(i + 1);
        on_path[k] = 0;
      }
    }
  };

  dfs(0);

  return res;
}

// leetcode46 <==> leetcode51
// leetcode51 N皇后
std::vector<std::vector<std::string>> LeetDFS::solveNQueens(int n) {
  // ans 20231115
  // 46的进阶，增加新的约束条件
  std::vector<std::vector<std::string>> res;
  std::vector<int> cols(n, 0);
  std::vector<int> on_path(n, 0);
  std::vector<int> left_top(2 * n - 1, 0);
  std::vector<int> right_top(2 * n - 1, 0);

  std::function<void(int)> dfs = [&](int row) {
    if (n == row) {
      std::vector<std::string> board(n);
      for (int i = 0; i < n; ++i)
        board[i] =
            std::string(cols[i], '.') + 'Q' + std::string(n - 1 - cols[i], '.');
      res.emplace_back(board);
    }

    for (int c = 0; c < n; c++) {
      int rc = row - c + n - 1;
      if (!on_path[c] && !left_top[row + c] && !right_top[rc]) {
        cols[row] = c;
        on_path[c] = 1;
        left_top[row + c] = 1;
        right_top[rc] = 1;
        dfs(row + 1);
        on_path[c] = 0;
        left_top[row + c] = 0;
        right_top[rc] = 0;
      }
    }
  };

  dfs(0);

  return res;
}

// leetcode494 目标和
int LeetDFS::findTargetSumWays(std::vector<int>& nums, int target) {
  // ans 20231116
  // 正号的数的和为p，nums的总和为s，那么负号数的和就是(s-p)，
  // 所以有 p - (s - p) = t
  // p = (s+t)/2
  // 问题就转换成找某一些数的和等于(s+t)/2的问题
  int res = 0;
  int n = nums.size();

  target += accumulate(nums.begin(), nums.end(), 0);
  if (target < 0 || (target % 2)) return 0;
  target /= 2;  // 现在问题就变成了，在nums中找若干个数和等于更新后的target

  // chache用于记忆化搜索
  std::vector<std::vector<int>> cache(n, std::vector<int>(target + 1, -1));
  std::function<int(int, int)> dfs = [&](int i, int t) {
    if (i < 0) {
      return int(0 == t);
    }
    int& cur = cache[i][t];
    if (-1 != cur) return cur;
    // 不能选
    if (nums[i] > t) return (cur = dfs(i - 1, t));
    // 可以选的情况下，有两种情况——选或者不选
    return (cur = dfs(i - 1, t) + dfs(i - 1, t - nums[i]));
  };

  return dfs(n - 1, target);
}

// leetcode1143 最长公共子序列
int LeetDFS::longestCommonSubsequence(std::string s, std::string t) {
  // 当前操作，s[i]和t[j]选或者不选
  // 子问题，s的前i和字母和t的前j和字母的LCS长度
  // 下一个子问题，s的前i-1个字母和t的前j-1个字母的LCS长度
  // s的前i-1个字母和t的前j个字母的LCS长度
  // s的前i个字母和t的前j-1个字母的LCS长度
  // dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1) + 1), s[i] = t[j];
  // dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1)), s[i] != t[j]

  // 简化以后
  // dfs(i, j) = dfs(i-1, j-1) + 1, s[i] = t[j];
  // dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1)), s[i] != t[j]
  int n = s.size();
  int m = t.size();

  // chache用于记忆化搜索
  std::vector<std::vector<int>> cache(n, std::vector<int>(m, -1));
  std::function<int(int, int)> dfs = [&](int i, int j) {
    if (i < 0 || j < 0) return 0;

    int& cur = cache[i][j];
    if (-1 != cur) return cur;
    if (s[i] == t[j])
      return cur = dfs(i - 1, j - 1) + 1;
    else
      return cur = std::max(dfs(i - 1, j), dfs(i, j - 1));
  };

  return dfs(n - 1, m - 1);
}

// leetcode1143 最长公共子序列
int LeetDFS::minDistance(std::string word1, std::string word2) {
  int n = word1.size();
  int m = word2.size();

  std::vector<std::vector<int>> cache(n, std::vector<int>(m, -1));
  std::function<int(int, int)> dfs = [&](int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    int& cur = cache[i][j];
    if (-1 != cur) return cur;

    if (word1[i] == word2[j])
      return cur = dfs(i - 1, j - 1) + 1;
    else
      return cur = std::min(std::min(dfs(i - 1, j), dfs(i, j - 1)),
                            (dfs(i - 1, j - 1) + 1));
  };

  return dfs(n - 1, m - 1);
}

// leetcode300 最长递增子序列
int LeetDFS::lengthOfLIS(std::vector<int>& nums) {
  int n = nums.size();

  std::vector<int> cache(n, 0);
  std::function<int(int)> dfs = [&](int i) {
    int& cur = cache[i];
    if (0 != cur) return cur;
    int j = 0;
    while (j < i) {
      if (nums[j] < nums[i]) {
        cur = std::max(cur, dfs(j));
      }
      j++;
    }
    return ++cur;
  };

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = std::max(res, dfs(i));
  }

  return res;
}

// leetcode516 最长回文子序列
int LeetDFS::longestPalindromeSubseq(std::string s) {
// resolve 20231120
#if 0
  int n = s.size();
  // cache用于记忆化搜索
  std::vector<std::vector<int>> cache(n, std::vector<int>(n, -1));
  std::function<int(int, int)> dfs = [&](int i, int j) {
    if (i == j)
      return 1;
    else if (i > j)
      return 0;

    int& cur = cache[i][j];
    if (-1 != cur) return cur;
    if (s[i] == s[j])
      return cur = dfs(i + 1, j - 1) + 2;
    else
      return cur = std::max(dfs(i, j - 1), dfs(i + 1, j));
  };

  return dfs(0, n - 1);
#else
  int n = s.size();
  std::vector<std::vector<int>> cache(n, std::vector<int>(n, 0));
  for (int i = n - 1; i >= 0; i--) {
    cache[i][i] = 0;
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j])
        cache[i][j] = cache[i + 1][j - 1] + 2;
      else
        cache[i][j] = std::max(cache[i][j - 1], cache[i + 1][j]);
    }
  }

  return cache[0][n - 1];

#endif
}

// leetcode1039 多边形三角剖分的最低得分
int LeetDFS::minScoreTriangulation(std::vector<int>& v) {
#if 0
  // ans 20231120
  int n = (int)v.size();
  std::vector<std::vector<int>> cache(n, std::vector<int>(n, -1));
  std::function<int(int, int)> dfs = [&](int i, int j) {
    // 构不成三角形
    if (i == j - 1) return 0;
    int& cur = cache[i][j];
    if (-1 != cur) return cur;
    cur = INT_MAX;
    for (int k = i + 1; k < j; k++) {
      cur = std::min(cur, dfs(i, k) + dfs(k, j) + v[i] * v[k] * v[j]);
    }
    return cur;
  };
  return dfs(0, n - 1);
#else
  int n = v.size();
  std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));
  for (int i = n - 3; i >= 0; i--) {
    for (int j = i + 2; j < n; j++) {
      f[i][j] = INT_MAX;
      for (int k = i + 1; k < j; k++) {
        f[i][j] = std::min(f[i][j], f[i][k] + f[k][j] + v[i] * v[k] * v[j]);
      }
    }
  }

  return f[0][n - 1];
#endif
}

}  // namespace myleet