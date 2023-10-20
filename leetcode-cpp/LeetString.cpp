#include "LeetString.h"

#include <iostream>
#include <vector>

namespace myleet {

// leetcode3最长无重复字符子串
int LeetString::lengthOfLongestSubstring(std::string s) {
  int m[256] = {0};
  int n = s.size();
  int res = 0, left = 0;
  for (int i = 0; i < n; i++) {
    if (m[s[i]] == 0 || m[s[i]] < left) {
      // res = max(res, i - left + 1);
      if ((i - left + 1) > res) {
        res = i - left + 1;
      }
    } else {
      left = m[s[i]];
    }
    m[s[i]] = i + 1;
  }

  return res;
}

// leet20合理的括号
bool LeetString::isValid(std::string s) {
  if (s.size() % 2) return false;

  std::vector<char> stack;
  for (int i = 0; i < s.size(); i++) {
    if ('(' == s[i])
      stack.emplace_back(')');
    else if ('[' == s[i])
      stack.emplace_back(']');
    else if ('{' == s[i])
      stack.emplace_back('}');
    else if (!stack.size())
      return false;
    else if (s[i] != stack[stack.size() - 1])
      return false;
    else
      stack.pop_back();
  }

  return stack.empty();
}

void genNext(const std::string &needle, std::vector<int> &next) {
  int n = needle.size();
  next.resize(n);
  next[0] = 0;
  for (int l = 0, r = 1; r < n; r++) {
    while (l > 0 && needle[l] != needle[r]) l = next[l - 1];
    if (needle[l] == needle[r]) l++;
    next[r] = l;
  }
}

// leetcode28 匹配子串
int LeetString::strStr(std::string haystack, std::string needle) {
  int type = 1;
  // 暴力法
  if (0 == type) {
    int ret = -1;
    int m = needle.size();
    int n = haystack.size();

    for (int i = 0; i < n; i++) {
      // std::string cur = haystack.substr(i, len);
      // if (needle == cur) {
      // ret = i;
      // break;
      // }
      bool match = true;
      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          match = false;
          break;
        }
      }

      if (true == match) {
        ret = i;
        break;
      }
    }

    return ret;
  } else if (1 == type) {
    // KMP算法
    std::string str = needle;
    std::vector<int> arr;
    genNext(str, arr);
    /*
    for (int i = 0; i < arr.size() - 1; i++) {
      std::cout << arr[i] << ",";
    }
    std::cout << arr[arr.size() - 1] << std::endl;
    */
    int n = haystack.size();
    int m = needle.size();
    for (int i = 0, j = 0; i < n; i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = arr[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == m) {
        return i - m + 1;
      }
    }

    return -1;
  }
}

}  // namespace myleet