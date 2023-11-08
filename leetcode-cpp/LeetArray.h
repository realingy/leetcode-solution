#ifndef __LEET_ARRAY_H__
#define __LEET_ARRAY_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace myleet {

class LeetArray {
 public:
  LeetArray() {}
  ~LeetArray() {}

 public:
  // leetcode1534 统计好三元组
  static int countGoodTriplets(std::vector<int>& arr, int a, int b, int c);
  // leetcode1566 重复至少 K 次且长度为 M 的模式
  static bool containsPattern(std::vector<int>& arr, int m, int k);
};

}  // namespace myleet

#endif