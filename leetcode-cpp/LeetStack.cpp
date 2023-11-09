#include "LeetStack.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode1021 删除最外层的括号
std::string LeetStack::removeOuterParentheses(std::string s) {
  // ans 20231107
  // 栈
  std::string res;
  std::vector<char> stack;
  for (char ch : s) {
    if (')' == ch) {
      stack.pop_back();
    }
    if (!stack.empty()) {
      res += ch;
    }
    if ('(' == ch) {
      stack.emplace_back(ch);
    }
  }

  return res;
}

// leetcode1047 删除字符串中的所有相邻重复项
std::string LeetStack::removeDuplicates(std::string s) {
  // resolve 20231107
  // 栈，逐个压栈，遇到和栈顶相等的出栈
  std::string res;
  std::vector<char> stack;

  for (char ch : s) {
    if (!stack.empty()) {
      if (ch == stack.back()) {
        stack.pop_back();
      } else {
        stack.emplace_back(ch);
      }
    } else {
      stack.emplace_back(ch);
    }
  }

  for (char ch : stack) {
    res += ch;
  }

  return res;
}

// leetcode71 简化路径
std::string LeetStack::simplifyPath(std::string path) {
  // resolve 20231109
  // stack,注意"."和空""不压栈
  int n = (int)path.size();
  int i = 0;
  int j = 0;
  std::vector<std::string> words;
  while (i < n && j < n) {
    while (i < n && '/' == path[i]) ++i;
    j = i;
    while (j < n && '/' != path[j]) ++j;
    words.emplace_back(path.substr(i, j - i));
    i = j;
    ++i;
  }

  /*
  for (std::string w : words) {
    std::cout << w << "|";
  }
  std::cout << "\n";
  */

  std::vector<std::string> stack;
  for (std::string w : words) {
    if (".." == w) {
      if (!stack.empty()) stack.pop_back();
    } else if ("." != w && "" != w) {
      stack.emplace_back(w);
    }
  }

  std::string res = "/";
  for (std::string w : stack) {
    if ("/" != w) res += w + "/";
  }
  if (res.size() > 1) res.pop_back();
  return res;
}

}  // namespace myleet