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

}  // namespace myleet