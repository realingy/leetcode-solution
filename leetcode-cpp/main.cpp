#include <iostream>

#include "LeetString.h"

using namespace myleet;

void ProcessString();

int main() {
  std::cout << "type: " << std::endl;
  std::cout << "index: " << std::endl;

  ProcessString();

  return 0;
}

// LeetString 字符串操作
void ProcessString() {
  // leet3
  if (0) {
    std::string str = "abcabc";
    // 最大无重复字符子串长度
    int len = LeetString::lengthOfLongestSubstring(str);
    std::cout << "len: " << len << std::endl;
  }

  // leet20
  if (0) {
    std::string str = "({})";
    bool valid = LeetString::isValid(str);
    std::cout << "valid: " << valid << std::endl;

    str = "(})";
    valid = LeetString::isValid(str);
    std::cout << "valid: " << valid << std::endl;
  }

  // leet28
  if (1) {
    LeetString::strStr("scddaabaaabsdfaabaaab", "aabaaab");
  }
}

// leet3-done
// leet20-done
// leet28-done