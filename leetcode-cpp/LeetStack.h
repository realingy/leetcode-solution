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
  // leetcode1047 删除字符串中的所有相邻重复项
  std::string removeDuplicates(std::string s);
  // leetcode71 简化路径
  std::string simplifyPath(std::string path);
};

}  // namespace myleet

#endif