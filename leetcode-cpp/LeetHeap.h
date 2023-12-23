#ifndef __LEETHEAP_H__
#define __LEETHEAP_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetHeap {
 public:
  LeetHeap() {}
  ~LeetHeap() {}

 public:
  // leetcode1962 移除石子使总数最小
  int minStoneSum(vector<int>& piles, int k) {
    make_heap(piles.begin(), piles.end());
    while (k-- && piles[0]) {
      pop_heap(piles.begin(), piles.end());
      piles.back() -= piles.back() / 2;
      push_heap(piles.begin(), piles.end());
    }
    return accumulate(piles.begin(), piles.end(), 0);
  }
};

}  // namespace myleet

#endif