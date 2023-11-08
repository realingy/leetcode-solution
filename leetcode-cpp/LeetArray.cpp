#include "LeetArray.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode1534 统计好三元组
int LeetArray::countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
  int res = 0;
  int n = arr.size();
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (std::abs(arr[j] - arr[i]) <= a && std::abs(arr[k] - arr[j]) <= b &&
            std::abs(arr[k] - arr[i]) <= c)
          res++;
      }
    }
  }

  return res;
}

bool samePattern(std::vector<int>& arr1, std::vector<int>& arr2) {
  if (arr1.size() != arr2.size()) return false;
  for (int i = 0; i < arr1.size(); i++) {
    if (arr1[i] != arr2[i]) return false;
  }
  return true;
}

std::vector<int> subPattern(std::vector<int>& arr, int s, int len) {
  std::vector<int> res;
  for (int i = s; i < s + len; i++) {
    res.emplace_back(arr[i]);
  }
  return res;
}

// leetcode1566 重复至少 K 次且长度为 M 的模式
bool LeetArray::containsPattern(std::vector<int>& arr, int m, int k) {
  int len = (int)arr.size();
  for (int i = 0; i < len; i++) {
    std::vector<int> cur = subPattern(arr, i, m);
    int count = 0;
    for (int j = i; j < len; j += m) {
      if (samePattern(cur, subPattern(arr, j, m))) {
        count++;
        if (k == count) return true;
      } else {
        cur = subPattern(arr, j, m);
        count = 0;
      }
    }
  }

  return false;
}

}  // namespace myleet