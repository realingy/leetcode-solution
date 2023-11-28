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

// leetcode2520 统计能整除数字的位数
int LeetBit::countDigits(int num) {
  // resolve 20231128
  // 枚举数位
  int x = num;
  int res = 0;
  while (x) {
    if (0 == num % (x % 10)) res++;
    x /= 10;
  }
  return res;
}

}  // namespace myleet
