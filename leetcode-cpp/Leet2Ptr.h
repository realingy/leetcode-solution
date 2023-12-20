#ifndef __LEET2PTR_H__
#define __LEET2PTR_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetTwoPtr {
 public:
  LeetTwoPtr() {}
  ~LeetTwoPtr() {}

 public:
  // leetcode151 反转字符串中的单词
  static string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    string res;
    int i = 0;
    while (i < n) {
      while (i < n && s[i] == ' ') i++;
      if (i >= n) break;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      reverse(s.begin() + i, s.begin() + j);
      res += s.substr(i, j - i);
      res += " ";
      i = ++j;
    }
    res.pop_back();
    return res;
  }
  // leetcode167 两数之和II-输入有序数组
  static vector<int> twoSum(vector<int>& nums, int t) {
    int i = 0;
    int j = (int)nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == t) {
        return {i + 1, j + 1};
      } else if (nums[i] + nums[j] < t) {
        i++;
      } else if (nums[i] + nums[j] > t) {
        j--;
      }
    }
    return {i + 1, j + 1};
  }
  // leetcode15 三数之和
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    int n = (int)nums.size();
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      // 优化1，考虑最小三个数和大于0
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
      // 优化2，考虑最小和最大两个数和小于0
      if (nums[i] + nums[n - 2] + nums[n - 1] < 0) break;
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (0 == sum) {
          res.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
          j++;
          while (j < k && nums[j] == nums[j - 1]) j++;
          k--;
          while (j < k && nums[k] == nums[k + 1]) k--;
        } else if (sum > 0) {
          k--;
        } else if (sum < 0) {
          j++;
        }
      }
    }

    return res;
  }
};

}  // namespace myleet

#endif