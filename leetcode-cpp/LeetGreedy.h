#ifndef __LEET_GREEDY_H__
#define __LEET_GREEDY_H__

#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetGreedy {
 public:
  LeetGreedy() {}
  ~LeetGreedy() {}

 public:
  // leetcode1217 玩筹码
  int minCostToMoveChips(vector<int>& position) {
    int c1 = 0;
    int c2 = 0;
    for (int x : position) {
      if (0 == x % 2) {
        c2++;
      } else {
        c1++;
      }
    }
    return min(c1, c2);
  }
};

}  // namespace myleet

#endif