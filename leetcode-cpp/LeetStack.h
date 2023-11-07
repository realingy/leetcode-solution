#ifndef __LEET_STACK_H__
#define __LEET_STACK_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetStack {
 public:
  LeetStack() {}
  ~LeetStack() {}

 public:
  // leetcode1021 删除最外层的括号
  std::string removeOuterParentheses(std::string s);
};

}  // namespace myleet

#endif