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

// 421. 数组中两个数的最大异或值
int LeetBit::findMaximumXOR(vector<int>& nums) {
#if 0
  int max = *max_element(nums.begin(), nums.end());
  int high_bit = max ? 31 - __builtin_clz(max) : -1;

  int res = 0, mask = 0;
  unordered_set<int> seen;
  for (int i = high_bit; i >= 0; i--) {
    seen.clear();
    mask |= 1 << i;                // mask的第i位被置为1
    int new_res = res | (1 << i);  // 这个比特位可以是0吗
    for (int x : nums) {
      x &= mask;  // 低于i的比特位被置为0
      if (seen.contains(new_res ^ x)) {
        res = new_res;  // 这个比特位可以为1
        break;
      }
      seen.insert(x);
    }
  }
  return res;
#endif
  // 库函数不能用，暂时屏蔽
  return 0;
}

// leetcode2864 最大二进制奇数
string maximumOddBinaryNumber(string s) {
  // resolve 20231202
  int cnt1 = std::count(s.begin(), s.end(), '1');
  return string(cnt1 - 1, '1') + string(s.length() - cnt1, '0') + '1';
  /*
  std::string res;
  for (int i = 0; i < cnt1 - 1; i++) {
    res += '1';
  }
  int n = s.size();
  for (int i = 0; i < n - cnt1; i++) {
    res += '0';
  }
  res += '1';
  return res;
  */
}

}  // namespace myleet
