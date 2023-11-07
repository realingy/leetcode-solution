#include "LeetStack.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode1021 删除最外层的括号
std::string LeetStack::removeOuterParentheses(std::string s) {
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

}  // namespace myleet