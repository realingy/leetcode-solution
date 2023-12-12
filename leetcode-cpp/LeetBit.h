#ifndef __LEET_BIT_H__
#define __LEET_BIT_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetBit {
 public:
  LeetBit() {}
  ~LeetBit() {}

 public:
  // leetcode2917 找出数组中的 K-or 值
  static int findKOr(std::vector<int>& nums, int k);
  // leetcode2520 统计能整除数字的位数
  static int countDigits(int num);
  // leetcode421 数组中两个数的最大异或值
  int findMaximumXOR(vector<int>& nums);
  // leetcode2317 操作后的最大异或和
  int maximumXOR(vector<int>& nums) {
    // nums[i] AND (nums[i] XOR x) 化简为 nums[i] NAD x
    // AND操作，1可以通过NAD操作变成0，反过来0不可以变成1
    // max xor(nums)
    // 最高位到最低位逐位考虑,如果比特位为1,则结果此比特位就可以变成1,所以简化成求nums的各个元素的OR运算
    int res = 0;
    for (int x : nums) {
      res |= x;
    }
    return res;
  }
};

}  // namespace myleet

#endif