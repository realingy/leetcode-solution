#ifndef __LEET_MATH_H__
#define __LEET_MATH_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetMath {
 public:
  LeetMath() {}
  ~LeetMath() {}

 private:
  long long pow(long long x, int n, int m) {
    long long res = 1;
    for (; n; n /= 2) {
      if (n % 2) res = res * x % m;
      x = x * x % m;
    }
    return res;
  }

 public:
  // leetcode2485 找出中枢整数
  int pivotInteger(int n);
  // leetcode2961 双模幂运算
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    // ans 20231211
    vector<int> res;
    int n = variables.size();
    for (int i = 0; i < n; i++) {
      auto v = variables[i];
      if (pow(pow(v[0], v[1], 10), v[2], v[3]) == target) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};

}  // namespace myleet

#endif