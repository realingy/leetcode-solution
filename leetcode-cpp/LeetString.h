#ifndef __LEETSTRING_H__
#define __LEETSTRING_H__

#include <string>

namespace myleet {
class LeetString {
 public:
  LeetString() {}
  ~LeetString() {}

 public:
  // leetcode3 最长无重复字符子串
  static int lengthOfLongestSubstring(std::string s);
  // leetcode20 合理的括号
  static bool isValid(std::string s);
  // leetcode28 匹配子串
  static int strStr(std::string haystack, std::string needle);
};
}  // namespace myleet

#endif