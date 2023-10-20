#include "LeetString.h"

#include <iostream>

namespace myleet {

// leetcode3最长无重复字符子串
int LeetString::lengthOfLongestSubstring(std::string s) {
  int m[256] = {0};
  int l = s.size();
  int res = 0, left = 0;
  for (int i = 0; i < l; i++) {
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

}  // namespace myleet