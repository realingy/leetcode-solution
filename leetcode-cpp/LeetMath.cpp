#include "LeetMath.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode2485 找出中枢整数
int LeetMath::pivotInteger(int n) {
  int x = (n + 1) * n / 2;
  int ret = std::sqrt(x);
  return x == ret * ret ? ret : -1;
}

}  // namespace myleet
