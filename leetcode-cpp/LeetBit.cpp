#include "LeetBit.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode2917 找出数组中的 K-or 值
int LeetBit::findKOr(std::vector<int>& nums, int k) {
  // ans 20231122
  // 知识：int整型小于2的31次方
  int res = 0;
  for (int i = 0; i < 31; i++) {
    int cnt = 0;
    for (int x : nums) {
      cnt += (x >> i) & 1;  // 第i位上的是否是1
    }
    if (cnt >= k) {
      res |= (1 << i);
    }
  }
  return res;
}

}  // namespace myleet
