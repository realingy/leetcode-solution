#ifndef __LEET_BIT_H__
#define __LEET_BIT_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

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
};

}  // namespace myleet

#endif