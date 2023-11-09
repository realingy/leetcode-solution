#include "LeetSort.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode169 多数元素
int LeetSort::majorityElement(std::vector<int>& nums) {
  // resolve 20231102
#if 0
  // 哈希表法
  int n = (int)nums.size();
  std::unordered_map<int, int> count;
  for (int& num : nums) {
    count[num]++;
  }

  int res = 0;
  for (std::pair<int, int> k : count) {
    // std::cout << "value: " << k.second << std::endl;
    if (k.second > n / 2) {
      res = k.first;
    }
  }

  return res;

#else
  // 投票法
  int x, v = 0;
  for (int& num : nums) {
    if (0 == v) x = num;
    if (x == num)
      v += 1;
    else
      v -= 1;
  }

  return x;
#endif
}

// leetcode217 存在重复元素
bool LeetSort::containsDuplicate(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int& num : nums) {
    if (count[num] > 0) return true;
    count[num]++;
  }

  return false;
}

// leetcode219 存在靠近的重复元素
bool LeetSort::containsNearbyDuplicate(std::vector<int>& nums, int k) {
  int len = (int)nums.size();
  std::unordered_map<int, int> count;
  for (int i = 0; i < len; i++) {
    int num = nums[i];
    if (count[num] > 0) {
      for (int j = 0; j < i; j++) {
        if (num == nums[j] && (i - j) <= k) {
          return true;
        }
      }
    }
    count[num]++;
  }

  return false;
}

// leetcode242 有效异位词
bool LeetSort::isAnagram(std::string s, std::string t) {
  // resolve 20231102
  if (s.size() != t.size()) return false;
#if 0
  // 哈希表
  int len = (int)s.size();
  std::unordered_map<char, int> count1;
  std::unordered_map<char, int> count2;
  for (char& ch : s) {
    count1[ch]++;
  }
  for (char& ch : t) {
    count2[ch]++;
  }

  for (std::pair<char, int> k : count1) {
    if (k.second != count2[k.first]) return false;
  }
  return true;
#else
  // 数组代替哈希表
  int len = (int)s.size();
  int count[26];
  memset(count, 0, sizeof(count));
  for (char& ch : s) {
    count[ch - 'a']++;
  }
  for (char& ch : t) {
    count[ch - 'a']--;
  }

  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
      return false;
    }
  }

  return true;
#endif
}

int LeetSort::missingNumber(std::vector<int>& nums) {
#if 0
  // ans
  // 位异或运算
  int res = 0;
  for (int& num : nums) {
    res ^= num;
  }
  int n = (int)nums.size();
  for (int i = 0; i <= n; i++) {
    res ^= i;
  }
  return res;
#else
  // resolve
  // 哈希表
  int res;
  int n = (int)nums.size();
  std::unordered_map<int, int> count;
  for (int& num : nums) {
    count[num]++;
  }
  for (int i = 0; i <= n; i++) {
    if (!count[i]) res = i;
  }
  return res;

#endif
}

// leetcode349 交集
std::vector<int> LeetSort::intersection(std::vector<int>& nums1,
                                        std::vector<int>& nums2) {
  // resolve 20231102
  // 双哈希表
  std::vector<int> res;
  int n = (int)nums1.size();
  std::unordered_map<int, int> count1;
  for (int& num : nums1) {
    count1[num]++;
  }
  std::unordered_map<int, int> count2;
  for (int& num : nums2) {
    count2[num]++;
  }

  for (std::pair<int, int> k : count1) {
    if (count2[k.first]) res.emplace_back(k.first);
  }

  return res;
}

// leetcode350 交集2
std::vector<int> LeetSort::intersection2(std::vector<int>& nums1,
                                         std::vector<int>& nums2) {
  // resolve 20231102
  // 双哈希表
  std::vector<int> res;
  int n = (int)nums1.size();
  std::unordered_map<int, int> count1;
  for (int& num : nums1) {
    count1[num]++;
  }
  std::unordered_map<int, int> count2;
  for (int& num : nums2) {
    count2[num]++;
  }

  for (std::pair<int, int> k : count1) {
    if (count2[k.first]) {
      int cnt;
      if (k.second < count2[k.first])
        cnt = k.second;
      else
        cnt = count2[k.first];
      for (int i = 0; i < cnt; i++) res.emplace_back(k.first);
    }
  }

  return res;
}

// leetcode389 找不同
char LeetSort::findTheDifference(std::string s, std::string t) {
  // resolve 20231102
  // 哈希表
  std::unordered_map<char, int> count;
  for (int i = 0; i < s.size(); i++) {
    char cur = s[i];
    count[cur]++;
  }
  for (int j = 0; j < t.size(); j++) {
    char cur = t[j];
    if (!count[cur]) return cur;
    count[cur]--;
  }
  return t[0];
}

// leetcode414 第三大数
int LeetSort::thirdMax(std::vector<int>& nums) {
  long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
  for (long num : nums) {
    if (num > a) {
      c = b;
      b = a;
      a = num;
    } else if (a > num && num > b) {
      c = b;
      b = num;
    } else if (b > num && num > c) {
      c = num;
    }
  }
  return c == LONG_MIN ? a : c;
}

// leetcode455 分饼干
int LeetSort::findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  // ans 20231102
  // 贪心+双指针

  //排序
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  //双指针
  int gr = g.size() - 1;
  int sr = s.size() - 1;

  //分饼干
  int n = 0;
  while (gr >= 0 && sr >= 0) {
    if (s[sr] >= g[gr]) {
      sr--;
      gr--;
      n++;
    } else {
      gr--;
    }
  }

  return n;
}

// leetcode506 相对名次
std::vector<std::string> LeetSort::findRelativeRanks(std::vector<int>& score) {
  // resolve 20231102
  // 哈希表+排序
  std::unordered_map<int, int> index;
  int len = (int)score.size();
  for (int i = 0; i < len; i++) {
    index[score[i]] = i;
  }

  std::vector<std::string> res(len);
  sort(score.begin(), score.end());
  for (int i = len - 1; i >= 0; i--) {
    int s = score[i];
    if (len - 1 == i) {
      res[index[s]] = "Gold Medal";
    } else if (len - 2 == i) {
      res[index[s]] = "Silver Medal";
    } else if (len - 3 == i) {
      res[index[s]] = "Bronze Medal";
    } else {
      int pos = len - i;
      res[index[s]] = std::to_string(pos);
    }
  }

  return res;
}

// leetcode561 拆分数组
int LeetSort::arrayPairSum(std::vector<int>& nums) {
  int res;
  sort(nums.begin(), nums.end());
  int len = (int)nums.size();
  for (int i = 0; i < len; i += 2) {
    res += nums[i];
  }

  return res;
}

// leetcode594 最长和谐子序列
int LeetSort::findLHS(std::vector<int>& nums) {
  // resolve 20231103
  // 哈希表
  std::unordered_map<int, int> count;
  for (int num : nums) {
    count[num]++;
  }

  int res = 0;
  for (int i = 0; i < nums.size(); i++) {
    int num = nums[i];
    if (!count[num + 1]) continue;
    if ((count[num] + count[num + 1]) > res) {
      res = count[num] + count[num + 1];
    }
  }

  return res;
}

int LeetSort::maximumProduct(std::vector<int>& nums) {
  // ans 20231103
  sort(nums.begin(), nums.end());

  int n = (int)nums.size();
  return std::max(nums[0] * nums[1] * nums[n - 1],
                  nums[n - 3] * nums[n - 2] * nums[n - 1]);
}

std::vector<int> LeetSort::findErrorNums(std::vector<int>& nums) {
  // unsolve
  std::vector<int> res(2);

  return res;
}

// leetcode747 至少是其他数字（次大值）两倍的最大数
int LeetSort::dominantIndex(std::vector<int>& nums) {
  // resolve 20231103
  // 遍历
  int res;
  int a = INT_MIN;
  int b = INT_MIN;

  for (int i = 0; i < nums.size(); i++) {
    int n = nums[i];
    if (n > a) {
      b = a;
      a = n;
      res = i;
    } else if (n > b && n < a) {
      b = n;
    }
  }

  if (a >= 2 * b)
    return res;
  else
    return -1;
}

// leetcode888 公平的糖果交换
std::vector<int> LeetSort::fairCandySwap(std::vector<int>& aliceSizes,
                                         std::vector<int>& bobSizes) {
#if 0
  // resolve 20231103
  // 在原数组上遍历
  std::vector<int> res;
  long long count1 = 0;
  long long count2 = 0;
  for (int s : aliceSizes) {
    count1 += s;
  }
  for (int s : bobSizes) {
    count2 += s;
  }

  long loss1 = count2 / 2 - count1 / 2;
  for (int s1 : aliceSizes) {
    int need = loss1 + s1;
    for (int s2 : bobSizes) {
      if (need == s2) {
        res.emplace_back(s1);
        res.emplace_back(s2);
        return res;
      }
    }
  }

  return res;
#else
  // ans 20231103
  // 排序+双指针
  std::vector<int> res;
  long long count1 = 0;
  long long count2 = 0;
  for (int s : aliceSizes) {
    count1 += s;
  }
  for (int s : bobSizes) {
    count2 += s;
  }

  long loss1 = (count2 - count1) / 2;

  sort(aliceSizes.begin(), aliceSizes.end());
  sort(bobSizes.begin(), bobSizes.end());

  int i = 0;
  int j = 0;
  int n1 = (int)aliceSizes.size();
  int n2 = (int)bobSizes.size();
  while (i < n1 && j < n2) {
    if (loss1 == bobSizes[j] - aliceSizes[i]) {
      res.emplace_back(aliceSizes[i]);
      res.emplace_back(bobSizes[j]);
      return res;
    } else if (loss1 < bobSizes[j] - aliceSizes[i]) {
      i++;
    } else if (loss1 > bobSizes[j] - aliceSizes[i]) {
      j++;
    }
  }

  return res;
#endif
}

// leetcode905 按奇偶数重新排列
std::vector<int> LeetSort::sortArrayByParity(std::vector<int>& nums) {
#if 0
  // resolve 20231103
  // 创建辅助数组放奇数
  std::vector<int> res;
  std::vector<int> arr1;
  for (int n : nums) {
    if (n % 2)
      arr1.emplace_back(n);
    else
      res.emplace_back(n);
  }

  for (int n : arr1) {
    res.emplace_back(n);
  }

  return res;
#else
  // resolve 20231103
  // 双指针
  int n = (int)nums.size();
  int i = 0;
  int j = n - 1;

  while (i < j) {
    // 左边找奇数
    while (i < j && !(nums[i] % 2)) {
      i++;
    }
    // 右边找偶数
    while (i < j && (nums[j] % 2)) {
      j--;
    }

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    i++;
    j--;
  }

  return nums;
#endif
}

std::vector<int> LeetSort::sortArrayByParityII(std::vector<int>& nums) {
  // resolve 20231103
  // 双指针
  int n = (int)nums.size();
  int i = 0;

  while (i < n) {
    if ((i % 2) && !(nums[i] % 2)) {
      // 找奇数
      int j = i + 1;
      while (j < n) {
        if (nums[j] % 2) {
          int temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
          break;
        }
        j++;
      }
    } else if (!(i % 2) && (nums[i] % 2)) {
      // 往后找偶数
      int j = i + 1;
      while (j < n) {
        if (!(nums[j] % 2)) {
          int temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
          break;
        }
        j++;
      }
    }
    i++;
  }

  return nums;
}

// leetcode976 最大周长
int LeetSort::largestPerimeter(std::vector<int>& nums) {
  // resolve 20231103
  // 排序，只需要判断相邻的三个数能不能组成三角形就可以了
  int n = (int)nums.size();
  sort(nums.begin(), nums.end());
  int i = n - 1;
  while (i >= 2) {
    if (nums[i] < nums[i - 1] + nums[i - 2])
      return nums[i] + nums[i - 1] + nums[i - 2];
    i--;
  }
  return 0;
}

// leetcode977 有序数组的平方
std::vector<int> LeetSort::sortedSquares(std::vector<int>& nums) {
  // resolve 20231103
  // 双指针
  int n = (int)nums.size();
  std::vector<int> res;
  res.resize(n);
  int i = 0;
  int j = n - 1;
  int idx = n - 1;

  while (i <= j) {
    int n1 = nums[i];
    int n2 = nums[j];
    if (n1 * n1 > n2 * n2) {
      res[idx--] = n1 * n1;
      i++;
    } else {
      res[idx--] = n2 * n2;
      j--;
    }
  }

  return res;
}

// leetcode1005 K次取反后最大化的数组和
int LeetSort::largestSumAfterKNegations(std::vector<int>& nums, int k) {
  int res = 0;
  int n = (int)nums.size();
  sort(nums.begin(), nums.end());
  while (k > 0) {
    nums[0] *= -1;
    sort(nums.begin(), nums.end());
    k--;
  }

  for (int n : nums) {
    res += n;
  }

  return res;
}

std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                                int cCenter) {
  // error 20231103
  // 错误解法，存在重复元素
  std::unordered_map<int, int> map;
  std::vector<int> distances;
  std::vector<std::vector<int>> pts;
  int index = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int dis = std::abs(rCenter - i) + std::abs(cCenter - j);
      map[index++] = dis;
      distances.emplace_back(dis);
      std::vector<int> pt = {i, j};
      pts.emplace_back(pt);
    }
  }

  std::vector<std::vector<int>> res;
  sort(distances.begin(), distances.end());
  for (int d : distances) {
    for (std::pair<int, int> k : map) {
      int dis = k.second;
      if (d == dis) {
        res.emplace_back(pts[k.first]);
      }
    }
  }
  return res;
}

// leetcode1051 高度检查器
int LeetSort::heightChecker(std::vector<int>& heights) {
  // resolve 20231103
  // 简单题
  int res = 0;
  std::vector<int> org;
  for (int h : heights) {
    org.emplace_back(h);
  }

  sort(heights.begin(), heights.end());

  int n = heights.size();
  for (int i = 0; i < n; i++) {
    if (heights[i] != org[i]) res++;
  }

  return res;
}

// leetcode1122 数组的相对排序
std::vector<int> LeetSort::relativeSortArray(std::vector<int>& arr1,
                                             std::vector<int>& arr2) {
  // resolve 20231103
  // 哈希表+排序
  sort(arr1.begin(), arr1.end());
  std::vector<int> res;
  std::unordered_map<int, int> count;
  for (int n : arr1) {
    count[n]++;
  }

  for (int n : arr2) {
    if (count[n]) {
      int c = count[n];
      for (int i = 0; i < c; i++) {
        res.emplace_back(n);
      }
      count[n] = 0;
    }
  }

  for (int n : arr1) {
    if (count[n]) {
      res.emplace_back(n);
    }
  }

  return res;
}

// leetcode1200 最小绝对差
std::vector<std::vector<int>> LeetSort::minimumAbsDifference(
    std::vector<int>& arr) {
  // resolve 20231103
  // 排序
  std::vector<std::vector<int>> res;
  sort(arr.begin(), arr.end());
  int n = (int)arr.size();
  int diff_min = INT_MAX;
  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] < diff_min) {
      diff_min = arr[i] - arr[i - 1];
    }
  }

  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] == diff_min) {
      std::vector<int> cur;
      cur.emplace_back(arr[i - 1]);
      cur.emplace_back(arr[i]);
      res.emplace_back(cur);
    }
  }

  return res;
}

// leetcode1331 数组序号转换
std::vector<int> LeetSort::arrayRankTransform(std::vector<int>& arr) {
  // resolve 20231103
  // 排序+哈希
  std::vector<int> res;
  if (!arr.size()) return res;

  std::vector<int> org;
  for (int n : arr) {
    org.emplace_back(n);
  }

  sort(arr.begin(), arr.end());
  std::unordered_map<int, int> index;
  int idx = 1;
  int cur = arr[0];
  for (int n : arr) {
    if (n > cur) {
      idx++;
      cur = n;
    }
    index[n] = idx;
  }

  for (std::pair<int, int> k : index) {
    std::cout << k.first << " " << k.second << "\n";
  }

  for (int n : org) {
    res.emplace_back(index[n]);
  }

  return res;
}

// leetcode1337 矩阵中战斗力最弱的 K 行
std::vector<int> LeetSort::kWeakestRows(std::vector<std::vector<int>>& mat,
                                        int k) {
  // resolve 20231103
  // 排序+哈希
  std::vector<int> powers;
  std::vector<int> sortpowers;
  std::unordered_map<int, int> map;
  int idx = 0;
  for (std::vector<int> m : mat) {
    int sum = 0;
    for (int n : m) {
      sum += n;
    }
    powers.emplace_back(sum);
    sortpowers.emplace_back(sum);
    map[idx++] = sum;
  }

  sort(sortpowers.begin(), sortpowers.end());

  std::vector<int> res;
  for (int i = 0; i < k; i++) {
    int power = sortpowers[i];
    for (int j = 0; j < mat.size(); j++) {
      if (map[j] == power) {
        res.emplace_back(j);
        if (k == res.size()) return res;
        map[j] = -1;
      }
    }
  }

  return res;
}

// leetcode56 合并区间
std::vector<std::vector<int>> LeetSort::merge(
    std::vector<std::vector<int>>& intervals) {
  // resolve 20231109
  // 排序+遍历
  // 排序后只需要比较res的最后一项和当前遍历到的项
  // 注意合并的时候需要比较第二项边界值
  if (intervals.size() == 0) {
    return {};
  }
  std::vector<std::vector<int>> res;
  std::sort(intervals.begin(), intervals.end());

  int n = (int)intervals.size();
  for (int i = 0; i < n; ++i) {
    int first = intervals[i][0];
    int second = intervals[i][1];
    if (res.empty() || res.back()[1] < first) {
      // 无需合并
      res.emplace_back(std::vector<int>{first, second});
    } else {
      // 合并
      res.back()[1] = std::max(res.back()[1], second);
    }
  }

  return res;
}

}  // namespace myleet
