#ifndef __LEETSTRING_H__
#define __LEETSTRING_H__

#include <string>

namespace myleet {
class LeetString {
 public:
  LeetString() {}
  ~LeetString() {}

 public:
  static int lengthOfLongestSubstring(
      std::string s);  // leetcode3最长无重复字符子串
};
}  // namespace myleet

#endif