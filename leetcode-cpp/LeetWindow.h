#ifndef __LEETWINDOW_H__
#define __LEETWINDOW_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetWindow {
 public:
  LeetWindow() {}
  ~LeetWindow() {}

 public:
  // leetcode2962 统计最大元素出现至少 K 次的子数组
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = *max_element(nums.begin(), nums.end());
    int cnt = 0, left = 0;
    long long res = 0;
    for (int x : nums) {
      cnt += x == mx;
      while (cnt == k) {
        cnt -= nums[left++] == mx;
      }
      res += left;
    }
    return res;
  }
};

}  // namespace myleet

#endif