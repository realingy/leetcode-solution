#include <iostream>

#include "LeetString.h"

using namespace myleet;

int main() {
  std::cout << "type: " << std::endl;
  std::cout << "index: " << std::endl;

  // [0] LeetString 字符串操作
  std::string str = "abcabc";
  // 最大无重复字符子串长度
  int len = LeetString::lengthOfLongestSubstring(str);
  std::cout << "len: " << len << std::endl;

  std::cout << "333333333\n";

  return 0;
}