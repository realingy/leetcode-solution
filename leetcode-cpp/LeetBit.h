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
  int findKOr(std::vector<int>& nums, int k);
};

}  // namespace myleet

#endif