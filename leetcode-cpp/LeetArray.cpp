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

// leetcode1925 统计平方和三元组的数目
int LeetArray::countTriples(int n) {
  int res = 0;
  for (int a = 1; a <= n; ++a) {
    for (int b = 1; b <= n; ++b) {
      int c = int(sqrt(a * a + b * b + 1.0));
      if (c <= n && c * c == a * a + b * b) {
        ++res;
      }
    }
  }
  return res;
}

// leetcode1995 统计特殊四元组
int LeetArray::countQuadruplets(std::vector<int>& nums) {
#if 0
  // resolve 20231108
  // 暴力法
  int res = 0;
  int n = (int)nums.size();
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      for (int c = b + 1; c < n; ++c) {
        for (int d = c + 1; d < n; ++d) {
          if (nums[a] + nums[b] + nums[c] == nums[d]) {
            ++res;
          }
        }
      }
    }
  }

  return res;
#else
  // ans 20231108
  // 哈希技巧
  int a, b, c, d;
  int n = (int)nums.size();

  std::unordered_map<int, int> count;
  int res = 0;

  for (int b = n - 3; b >= 1; b--) {
    int c = b + 1;
    for (int d = c + 1; d < n; d++) {
      count[nums[d] - nums[c]]++;
    }
    for (int a = 0; a < b; a++) {
      res += count[nums[a] + nums[b]];
    }
  }

  return res;
#endif
}

// leetcode2094 找出3位偶数
std::vector<int> LeetArray::findEvenNumbers(std::vector<int>& digits) {
  // ans 20231108
  // 哈希set(重点，过滤重复结果)+枚举
  int n = (int)digits.size();
  std::unordered_set<int> nums;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || j == k || i == k) {
          continue;
        }
        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
        if (num >= 100 && num % 2 == 0) {
          nums.insert(num);
        }
      }
    }
  }

  std::vector<int> res;
  for (const int n : nums) {
    res.emplace_back(n);
  }
  std::sort(res.begin(), res.end());

  return res;
}

// leetcode2259 移除指定数字得到的最大结果
std::string LeetArray::removeDigit(std::string number, char digit) {
  std::string res;
  int n = (int)number.size();
  for (int i = 0; i < n; i++) {
    if (number[i] == digit) {
      std::string tmp = number.substr(0, i);
      tmp += number.substr(i + 1, n - i);
      res = std::max(res, tmp);
    }
  }
  return res;
}

// leetcode2309 兼具大小写的最好英文字母
std::string LeetArray::greatestLetter(std::string s) {
  // resolve 20231108
  // 哈希
  std::string res = "";
  int count1[26];
  int count2[26];
  memset(count1, 0, sizeof(count1));
  memset(count2, 0, sizeof(count2));

  for (char ch : s) {
    if (ch >= 'A' && ch <= 'Z') {
      count1[ch - 'A']++;
    }
    if (ch >= 'a' && ch <= 'z') {
      count2[ch - 'a']++;
    }
  }

  int idx = -1;
  for (int i = 0; i < 26; i++) {
    if (count1[i] && count2[i]) idx = std::max(idx, i);
  }

  if (idx >= 0) res += (idx + 'A');

  return res;
}

// leetcode2367 算术三元组的数目
int LeetArray::arithmeticTriplets(std::vector<int>& nums, int diff) {
  // resolve 20231108
  // 暴力枚举
  int res = 0;
  int n = (int)nums.size();
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      if (nums[j] - nums[i] != diff) {
        continue;
      }
      for (int k = j + 1; k < n; k++) {
        if (diff == nums[k] - nums[j]) {
          res++;
        }
      }
    }
  }

  return res;
}

// leetcode2427 公因子的数目
int LeetArray::commonFactors(int a, int b) {
  // resolve 20231108
  // 暴力枚举
  int res = 0;
  int min = std::min(a, b);
  for (int i = 1; i <= min; i++) {
    if (0 == a % i && 0 == b % i) {
      res++;
    }
  }

  return res;
}

// leetcode2437 有效时间的数目
int LeetArray::countTime(std::string time) {
  // resolve 20231108
  // 暴力枚举
  int res = 1;
  char a = time[0];
  char b = time[1];
  char c = time[3];
  char d = time[4];

  if ('?' == d) {
    res *= 10;
  }
  if ('?' == c) {
    res *= 6;
  }
  if ('?' == a && '?' == b) {
    res *= 24;
  } else if ('?' == a) {
    if (b >= '4' && b <= '9') res *= 2;
    if (b < '4') res *= 3;
  } else if ('?' == b && '2' == a) {
    res *= 4;
  } else if ('?' == b && '2' != a) {
    res *= 10;
  }

  return res;
}

// leetcode2605 从两个数字数组里生成最小数字
int LeetArray::minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
  // resolve 20231108
  // 哈希
  int count1[10];
  int count2[10];
  memset(count1, 0, sizeof(count1));
  memset(count2, 0, sizeof(count2));
  int min1 = INT_MAX;
  for (int n : nums1) {
    count1[n]++;
    min1 = std::min(min1, n);
  }
  int min2 = INT_MAX;
  for (int n : nums2) {
    count2[n]++;
    min2 = std::min(min2, n);
  }

  for (int i = 1; i <= 9; i++) {
    if (count1[i] && count2[i]) {
      return i;
    }
  }

  if (min1 < min2)
    return min1 * 10 + min2;
  else
    return min2 * 10 + min1;
}

// leetcode2765 最长交替子序列
int LeetArray::alternatingSubarray(std::vector<int>& nums) {
  // ans 20231108
  // 枚举
  int res = 0;
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    int j = i;
    int cut = 1;
    while (j + 1 < n && cut == nums[j + 1] - nums[j]) {
      cut *= -1;
      j++;
    }
    // 这里特判 只有一个元素时不成立
    // 同时将下次 i 的位置移动到位置 j 上
    if (i != j) {
      res = std::max(res, j - i + 1);
      i = j - 1;
    }
  }

  return !res ? -1 : res;
}

// leetcode2798 满足目标工作时长的员工数目
int LeetArray::numberOfEmployeesWhoMetTarget(std::vector<int>& hours,
                                             int target) {
  int res = 0;
  for (int h : hours) {
    if (h >= target) res++;
  }
  return res;
}

// leetcode2843 统计对称整数的数目
int LeetArray::countSymmetricIntegers(int low, int high) {
#if 0
  // resolve 20231108
  // 暴力枚举
  int res = 0;
  for (int i = low; i <= high; i++) {
    std::string s = std::to_string(i);
    int n = (int)s.size();
    if (0 != n % 2) continue;
    long long count1 = 0;
    for (int i = 0; i < n / 2; i++) {
      count1 += (s[i] - '0');
    }
    long long count2 = 0;
    for (int i = n / 2; i < n; i++) {
      count2 += (s[i] - '0');
    }
    if (count1 == count2) res++;
  }

  return res;
#else
  int res = 0;
  for (int i = low; i <= high; i++) {
    std::string s = std::to_string(i);
    int n = (int)s.size();
    if (0 != n % 2) continue;
    int diff = 0;
    for (int j = 0; j < n / 2; j++) {
      diff += s[j] - s[j + n / 2];
    }
    if (!diff) res++;
  }
  return res;

#endif
}

// leetcode845 数组中的最长山脉
int LeetArray::longestMountain(std::vector<int>& arr) {
  if (arr.size() < 3) return 0;
  int res = 0;
  int n = (int)arr.size();
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] <= arr[i - 1] || arr[i] <= arr[i + 1]) continue;
    int j = i - 1;
    int k = i + 1;
    int len1 = 0;
    while (j >= 0) {
      if (arr[j] < arr[j - 1]) {
        len1++;
        j--;
      } else {
        break;
      }
    }

    int len2 = 0;
    while (k < n) {
      if (arr[k] < arr[k + 1]) {
        len2++;
        k++;
      } else {
        break;
      }
    }

    res = std::max(len1 + len2, res);
  }

  return res > 0 ? res + 1 : res;
}

// leetcode949 给定数字能组成的最大时间
std::string LeetArray::largestTimeFromDigits(std::vector<int>& arr) {
  int res = -1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j == i) continue;
      for (int k = 0; k < 4; k++) {
        if (k == i || k == j) continue;
        int l = 6 - i - j - k;
        int hours = 10 * arr[i] + arr[j];
        int mins = 10 * arr[k] + arr[l];
        if (hours < 24 && mins < 60) {
          res = std::max(res, hours * 60 + mins);
        }
      }
    }
  }

  if (res >= 0) {
    std::string str;
    if (res / 60 < 10) str += '0';
    str += std::to_string(res / 60);
    str += ':';
    if (res % 60 < 10) str += '0';
    str += std::to_string(res % 60);
    return str;
  }
  return "";
}

// leetcode1291 顺次数
std::vector<int> LeetArray::sequentialDigits(int low, int high) {
#if 0
  // unresolve 20231108
  // 超时
  std::vector<int> res;
  for (int i = low; i <= high;) {
    std::string s = std::to_string(i);
    int n = (int)s.size();
    bool match = true;
    for (int j = 1; j < n; j++) {
      if (s[j] - s[j - 1] != 1) {
        match = false;
        break;
      }
    }
    if (true == match) {
      res.emplace_back(i);
      i += 10 * n * (s[0] - '0');
    } else {
      i++;
    }
  }

  return res;
#else
  std::vector<int> res;
  // ans 20231108
  // 枚举所有可能的顺序数
  for (int i = 1; i <= 9; ++i) {
    int num = i;
    for (int j = i + 1; j <= 9; ++j) {
      num = num * 10 + j;
      std::cout << num << ", ";
      if (num >= low && num <= high) {
        res.emplace_back(num);
      }
    }
  }

  std::cout << std::endl;

  std::sort(res.begin(), res.end());

  return res;
#endif
}

// leetcode1620 网络信号最好的坐标
std::vector<int> LeetArray::bestCoordinate(
    std::vector<std::vector<int>>& towers, int radius) {
  int x_max = 0;
  int y_max = 0;
  for (std::vector<int>& t : towers) {
    x_max = std::max(t[0], x_max);
    y_max = std::max(t[1], y_max);
  }

  int max_sig = INT_MIN;
  int local_x = 0;
  int local_y = 0;
  for (int i = 0; i <= x_max; i++) {
    for (int j = 0; j <= y_max; j++) {
      int count = 0;
      for (std::vector<int>& t : towers) {
        double distance = (i - t[0]) * (i - t[0]) + (j - t[1]) * (j - t[1]);
        if (distance <= radius * radius) {
          count += (int)(t[2] / (1 + sqrt(distance)));
        }
      }

      if (count > max_sig) {
        max_sig = count;
        local_x = i;
        local_y = j;
      }
    }
  }

  return {local_x, local_y};
}

// leetcode167 两数之和II-输入有序数组
std::vector<int> LeetArray::twoSum(std::vector<int>& numbers, int target) {
  std::vector<int> res;
  int i = 0;
  int j = (int)numbers.size() - 1;
  while (i < j) {
    if (numbers[i] + numbers[j] == target) {
      res.emplace_back(i);
      res.emplace_back(j);
      break;
    } else if (numbers[i] + numbers[j] < target) {
      i++;
    } else if (numbers[i] + numbers[j] > target) {
      j--;
    }
  }

  return res;
}

// leetcode15 三数之和
std::vector<std::vector<int>> LeetArray::threeSum(std::vector<int>& nums) {
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
        while (j < k && nums[j] == nums[j - 1]) {
          j++;
        }
        k--;
        while (j < k && nums[k] == nums[k + 1]) {
          k--;
        }
      } else if (sum > 0) {
        k--;
      } else if (sum < 0) {
        j++;
      }
    }
  }

  return res;
}

// leetcode11 盛最多水的容器
int LeetArray::maxArea(std::vector<int>& height) {
  // ans 20231108
  // 双指针
  int i = 0, j = height.size() - 1, res = 0;
  while (i < j) {
    res = height[i] < height[j] ? std::max(res, (j - i) * height[i++])
                                : std::max(res, (j - i) * height[j--]);
  }
  return res;
}

// leetcode42 接雨水
int LeetArray::trap(std::vector<int>& height) {
  int n = (int)height.size();
  std::vector<int> prev_max(n);
  std::vector<int> post_max(n);
  prev_max[0] = height[0];
  for (int i = 1; i < n; i++) {
    prev_max[i] = std::max(prev_max[i - 1], height[i]);
  }
  post_max[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    post_max[i] = std::max(post_max[i + 1], height[i]);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    int h = std::min(prev_max[i], post_max[i]);
    res += h - height[i];
  }

  return res;
}

// leetcode49 字母异位词分组
std::vector<std::vector<std::string>> LeetArray::groupAnagrams(
    std::vector<std::string>& strs) {
  // resolve 20231109
  // 哈希+排序
  std::unordered_map<std::string, std::vector<std::string>> mp;
  for (std::string s : strs) {
    std::string tmp = s;
    std::sort(tmp.begin(), tmp.end());
    mp[tmp].emplace_back(s);
  }
  std::vector<std::vector<std::string>> res;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    res.emplace_back(it->second);
  }
  return res;
}

// leetcode57 插入区间
std::vector<std::vector<int>> LeetArray::insert(
    std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
  // resolve 20231109
  // 遍历,三个while解决问题
  if (intervals.size() == 0) {
    return std::vector<std::vector<int>>{newInterval};
  }

  int left = newInterval[0];
  int right = newInterval[1];
  std::vector<std::vector<int>> res;
  int n = (int)intervals.size();

  // 1
  int i = 0;
  while (i < n && intervals[i][1] < left) {
    res.emplace_back(intervals[i]);
    ++i;
  }

  // 2
  // 注意判断i的范围
  int l = i < n ? std::min(intervals[i][0], left) : left;
  while (i < n && intervals[i][0] <= right) {
    ++i;
  }
  if (i > 0) {
    res.emplace_back(std::vector<int>{l, std::max(intervals[i - 1][1], right)});
  } else {
    res.emplace_back(std::vector<int>{l, right});
  }

  // 3
  while (i < n) {
    int l = intervals[i][0];
    int r = intervals[i][1];
    res.emplace_back(std::vector<int>{l, r});
    ++i;
  }

  return res;
}

// leetcode58 最后一个单词的长度
int LeetArray::lengthOfLastWord(std::string s) {
  // resolve 20231109
  // 双指针，从后往前遍历
  int n = (int)s.size();
  int i = n - 1;
  while (i >= 0 && ' ' == s[i]) --i;
  int j = i;
  while (j >= 0 && ' ' != s[j]) --j;
  return i - j;
}

// leetcode209 <==> leetcode713 <==> leetcode3
// leetcode209 长度最小的子数组
int LeetArray::minSubArrayLen(int target, std::vector<int>& nums) {
#if 0
  // ans 20231109
  // 双指针+滑动窗口
  // 时间复杂度O(n)，因为双指针i和j只在[0，n]区间变动一次
  int n = (int)nums.size();
  int res = n + 1;
  int count = 0;
  int i = 0;
  int j = 0;
  while (j < n) {
    count += nums[j];
    while (count - nums[i] >= target) {
      count -= nums[i];
      i++;
    }

    if (count >= target) res = std::min(res, j - i + 1);
    ++j;
  }

  return res <= n ? res : 0;
#else
  int n = (int)nums.size();
  int res = n + 1;
  int count = 0;
  int i = 0;
  int j = 0;
  while (j < n) {
    count += nums[j];
    while (count >= target) {
      res = std::min(res, j - i + 1);
      count -= nums[i];
      ++i;
    }
    ++j;
  }

  return res <= n ? res : 0;
#endif
}

// leetcode209 <==> leetcode713 <==> leetcode3
// leetcode713 乘积小于K的子数组
int LeetArray::numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
  // 双指针+滑动窗口
  if (k <= 1) return 0;
  int res = 0;
  int prod = 1;
  int i = 0;
  int j = 0;
  int n = (int)nums.size();
  // 得到一个右端点，枚举以此右端点实现最长的乘积小于k的子数列的数目
  while (j < n) {
    prod *= nums[j];
    while (prod >= k) {
      prod /= nums[i];
      i++;
    }
    res += j - i + 1;
    ++j;
  }

  return res;
}

// leetcode3 无重复字符的最长子串
int LeetArray::lengthOfLongestSubstring(std::string s) {
#if 1
  // 双指针+滑动窗口+借助于哈希表
  int res = 0;
  std::unordered_map<char, int> count;
  int i = 0;
  int j = 0;
  int n = (int)s.size();
  while (j < n) {
    count[s[j]]++;
    while (count[s[j]] > 1) {
      count[s[i]]--;
      i++;
    }
    res = std::max(res, j - i + 1);
  }

  return res;
#else
  int m[256] = {0};
  int n = s.size();
  int res = 0, left = 0;
  for (int i = 0; i < n; i++) {
    if (m[s[i]] == 0 || m[s[i]] < left) {
      res = max(res, i - left + 1);
    } else {
      left = m[s[i]];
    }
    m[s[i]] = i + 1;
  }
  return res;
#endif
}

// leetcode74 搜索二维矩阵
bool LeetArray::searchMatrix(std::vector<std::vector<int>>& matrix,
                             int target) {
  // resolve 20231110
  // 数组的二分查找
  if (matrix.empty() || matrix[0].empty()) return 0;
  int left = 0, right = (int)matrix.size() * (int)matrix[0].size() - 1;
  int n = (int)matrix[0].size();
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (matrix[mid / n][mid % n] > target) {
      right = mid - 1;
    } else if (matrix[mid / n][mid % n] < target) {
      left = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

// leetcode75 颜色分类
void LeetArray::sortColors(std::vector<int>& nums) {
#if 0
  // resolve 20231110
  // 一次遍历
  int n = (int)nums.size();
  int i0 = 0, i1 = 0, i2 = 0;
  for (int i = 0; i < n; i++) {
    if (0 == nums[i]) {
      nums[i2++] = 2;
      nums[i1++] = 1;
      nums[i0++] = 0;
    } else if (1 == nums[i]) {
      nums[i2++] = 2;
      nums[i1++] = 1;
    } else if (2 == nums[i]) {
      nums[i2++] = 2;
    }
  }
#else
  // resolve 20231110
  // 三指针
  int i = 0, j = 0, k = nums.size() - 1;
  while (j <= k) {
    if (nums[j] == 0)
      std::swap(nums[i++], nums[j++]);
    else if (nums[j] == 2)
      std::swap(nums[j], nums[k--]);
    else
      j++;
  }
#endif
}

// nums是非递减的，返回最小满足nums[i]>=target的下标，如果不存在返回nums的长度
int low_bound(std::vector<int>& nums, int target) {
  // 闭区间[left, right]
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

// leetcode34 在排序数组中查找元素的第一个和最后一个位置
std::vector<int> LeetArray::searchRange(std::vector<int>& nums, int target) {
  int left = low_bound(nums, target);
  if (left == nums.size() || target != nums[left]) {
    return {-1, -1};
  }
  int right = low_bound(nums, target + 1) - 1;
  return {left, right};
}

// leetcode162 寻找峰值
int LeetArray::findPeakElement(std::vector<int>& nums) {
  // ans 20231111
  // 闭区间[0,n-2]等效于开区间(0,n-1)
  int n = nums.size();
  int left = -1;
  int right = n - 1;
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return right;
}

// leetcode153 寻找旋转数组的最小值
int LeetArray::findMin(std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;
  if (nums[left] > nums[right]) {
    while (left < right - 1) {
      mid = left + (right - left) / 2;
      if (nums[left] < nums[mid])
        left = mid;
      else if (nums[right] > nums[mid])
        right = mid;
    }
  }

  return std::min(nums[left], nums[right]);
}

// 当前序号是蓝色的意思是在target的右边
bool isBlue(int i, std::vector<int>& nums, int target) {
  int end = nums[nums.size() - 1];
  if (nums[i] > end) {
    // nums[i]位于旋转有序数组的左半部分，target在nums[i]的左边的充要条件是nums[i]大于等于target且target在左半部分【target
    // > end】
    return (target > end) && (nums[i] >= target);
  } else {
    // nums[i]位于旋转有序数组的右半部分，target在nums[i]的左边的充要条件是nums[i]大于等于target或者target在左半部分【target
    // > end】
    return (target > end) || (nums[i] >= target);
  }
}

// leetcode33 搜索旋转排序数组
int LeetArray::search(std::vector<int>& nums, int target) {
  int left = -1;
  int right = nums.size();
  int mid = 0;
  while (left < right - 1) {
    mid = left + (right - left) / 2;
    if (!isBlue(mid, nums, target))
      left = mid;
    else
      right = mid;
  }

  if (nums[right] != target || nums.size() == right) return -1;

  return right;
}

// leetcode35 搜索插入位置
int LeetArray::searchInsert(std::vector<int>& nums, int target) {
  int left = -1;
  int right = nums.size();
  int mid = 0;
  while (left < right - 1) {
    mid = left + (right - left) / 2;
    if (nums[mid] < target)
      left = mid;
    else
      right = mid;
  }
  return right;
}

// leetcode会提供此函数
bool isBadVersion(int idx) {
  std::cout << "leetcode会提供此函数\n";
  return true;
}

// leetcode278 第一个错误的版本
int LeetArray::firstBadVersion(int n) {
  int left = -1;
  int right = n;
  int mid = 0;

  while (left < right - 1) {
    mid = left + (right - left) / 2;
    if (!isBadVersion(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return right;
}

// leetcode202 快乐数
bool LeetArray::isHappy(int n) {
  // resolve 20191119
  // 循环+哈希
  int sum = 0;
  std::unordered_set<int> s;
  while (n != 1) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    n = sum;
    if (s.count(n))
      // 如果又循环回原来的数，那么接下来可以不用继续判断了
      break;
    else
      s.insert(n);
  }
  return n == 1;
}

// leetcode2937. 使三个字符串相等
int LeetArray::findMinimumOperations(std::string s1, std::string s2,
                                     std::string s3) {
  // resolve 20231121
  // 问题转换成求最大共同前缀的长度，如果为零则三个字符串的第一个字符不相等，返回-1
  int n = std::min(std::min(s1.size(), s2.size()), s3.size());
  int i = 0;
  while (i < n && s1[i] == s2[i] && s1[i] == s3[i]) {
    i++;
  }

  return !i ? -1 : s1.size() + s2.size() + s3.size() - 3 * i;
}

// leetcode2938 区分黑球与白球
long long LeetArray::minimumSteps(std::string s) {
  long long res = 0;
  int cnt1 = 0;
  for (char& ch : s) {
    if ('1' == ch)
      cnt1++;
    else
      res += cnt1;
  }
  return res;
}

// leetcode2939 最大异或乘积
int LeetArray::maximumXorProduct(long long a, long long b, int n) {
  long long mod = std::pow(10, 9) + 7;
  long long res = a * b;
  for (int i = 0; i < n; i++) {
    long long aa = a ^ (1 << i);
    long long bb = b ^ (1 << i);
    if (aa * bb > a * b) {
      a = aa;
      b = bb;
      res = aa * bb;
    }
  }

  return res % mod;
}

// leetcode2760 最长奇偶子数组
int LeetArray::longestAlternatingSubarray(std::vector<int>& nums,
                                          int threshold) {
  // resolve 20231121
  // 滑动窗口
  int n = nums.size();
  int i = 0;
  int res = 0;
  while (i < n) {
    if (nums[i] > threshold || 0 != nums[i] % 2) {
      i++;
      continue;
    }
    int j = i;
    i++;
    while (i < n && nums[i] % 2 != nums[i - 1] % 2 && nums[i] <= threshold) {
      i++;
    }
    res = std::max(res, i - j);
  }
  return res;
}

// leetcode2932 找出强数对的最大异或值I
int LeetArray::maximumStrongPairXor(std::vector<int>& nums) {
  // resolve 20231121
  // 排序，将强数对转换成 2*x >= y 的问题
  std::sort(nums.begin(), nums.end());
  int n = nums.size();
  int i = 0;
  int res = INT_MIN;
  while (i < n) {
    int j = i;
    while (j >= 0) {
      if (2 * nums[j] >= nums[i]) {
        res = std::max(res, nums[j] ^ nums[i]);
      } else {
        break;
      }
      j--;
    }
    i++;
  }
  return res;
}

// leetcode2935 找出强数对的最大异或值II
int LeetArray::maximumStrongPairXor2(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int n = nums.size();
  int i = 0;
  int res = INT_MIN;
  while (i < n) {
    int j = i;
    while (j >= 0) {
      if (2 * nums[j] >= nums[i]) {
        res = std::max(res, nums[j] ^ nums[i]);
      } else {
        break;
      }
      j--;
    }
    i++;
  }
  return res;
}

// leetcode2934 最大化数组末位元素的最少操作次数
int LeetArray::minOperations(std::vector<int>& nums1, std::vector<int>& nums2) {
  // ans 20231121
  // 逐个判断前n-1个元素，如果比最后一个数大就必须交换，交换后如果还不满足那就直接返回-1
  int n = nums1.size();

  std::function<int(int, int)> f = [&](int last1, int last2) {
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = nums1[i], y = nums2[i];
      if (x > last1 || y > last2) {
        if (x > last2 || y > last1) {
          return n + 1;
        }
        res++;
      }
    }
    return res;
  };

  // 第一种情况是直接逐个判断前n-1个元素，第二种情况是先交换最后元素，然后继续判断前n-1个元素
  int r = std::min(f(nums1[n - 1], nums2[n - 1]),
                   1 + f(nums2[n - 1], nums1[n - 1]));

  return r > n ? -1 : r;
}

// leetcode2928 <==> leetcode2929 <==> leetcode2927
// leetcode2928 给小朋友们分糖果 I
int LeetArray::distributeCandies(int n, int limit) {
  // ans 20231121
  // O(1) 容斥原理
  // f(n+2): 所有的方案
  // 3 * f(n - (limit + 1) + 2)：至少有1个小朋友分到超过limit糖果的方案
  // 3 * f(n - 2*(limit + 1) + 2)：至少有2个小朋友分到超过limit糖果的方案
  // f(n - 3*(limit + 1) + 2)：3个小朋友分到超过limit糖果的方案
  std::function<int(int)> f = [&](int n) {
    return n > 1 ? n * (n - 1) / 2 : 0;
  };

  return f(n + 2) - 3 * f(n - (limit + 1) + 2) +
         3 * f(n - 2 * (limit + 1) + 2) - f(n - 3 * (limit + 1) + 2);
}

// leetcode2928 <==> leetcode2929 <==> leetcode2927
// leetcode2929 给小朋友们分糖果II
long long LeetArray::distributeCandies2(int n, int limit) {
#if 0
  // error 20231121
  // 超时
  long long res = 0;
  int a = 0;
  while (a <= limit) {
    int b = 0;
    while (b <= limit) {
      int c = n - a - b;
      if (c <= limit && c >= 0) {
        res++;
      }
      b++;
    }
    a++;
  }
  return res;
#else
  // ans 20231121
  // O(1) 容斥原理
  // f(n+2): 所有的方案
  // 3 * f(n - (limit + 1) + 2)：至少有1个小朋友分到超过limit糖果的方案
  // 3 * f(n - 2*(limit + 1) + 2)：至少有2个小朋友分到超过limit糖果的方案
  // f(n - 3*(limit + 1) + 2)：3个小朋友分到超过limit糖果的方案
  std::function<long long(long long)> f = [&](long long n) {
    return n > 1 ? n * (n - 1) / 2 : 0;
  };

  return f(n + 2) - 3 * f(n - (limit + 1) + 2) +
         3 * f(n - 2 * (limit + 1) + 2) - f(n - 3 * (limit + 1) + 2);
#endif
}

// leetcode2928 <==> leetcode2929 <==> leetcode2927
// leetcode2927 给小朋友们分糖果III
long long LeetArray::distributeCandies3(int n, int limit) {
  // VIP
  return (long long)0;
}

// leetcode2930 重新排列后包含指定子字符串的字符串数目
int LeetArray::stringCount(int n) {
  // ans 20231121
  // A
  // n个字母的全排列26^n，去掉不能满足组成leet的排列
  // B
  // 1）不含l，25^n
  // 2）不含t，25^n
  // 3）不含e或者只有一个e，25^+n*25^(n-1)
  // 直接去掉会重复计算至少满足两个条件的情况，需要先去除
  // C
  // 1) 不含l和t，24^n
  // 2) 不含l且e的个数小于2，24^n + n*24^(n-1)
  // 3) 不含t且e的个数小于2，24^n + n*24^(n-1)
  // 直接去掉会重复计算满足三个条件的情况，需要先去除
  // D
  // 不含l和t且e的个数小于2，23^n+n*23^(n-1)
  // 最终的结果等于 A - (B - (C - D)) ==> A - B + C - D

  // 不含leet的字符串的个数为「至少满足一个条件」减去「至少满足两个条件」加上「满足三个条件」，容斥原理。
  const long long mod = 1e9 + 7;
  std::function<long long(long long, int)> p = [&](long long x, int i) {
    long long res = 1;
    for (; i; i /= 2) {
      if (i % 2) {
        res = res * x % mod;
      }
      x = x * x % mod;
    }
    return res;
  };

  return ((p(26, n) - p(25, n - 1) * (75 + n) + p(24, n - 1) * (72 + 2 * n) -
           p(23, n - 1) * (23 + n)) %
              mod +
          mod) %
         mod;
}

int findChampion(std::vector<std::vector<int>>& grid) {
  // resolve 20231121
  // 逐行比较，两行相减如果有其中一个差大于0，说明当前行是强的那个，记录强者的行号，然后继续遍历下一行
  int n = grid.size();
  int m = grid[0].size();
  if (1 == n) return 0;
  int res = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] - grid[res][j] > 0) {
        res = i;
        break;
      }
    }
  }

  return res;
}

// leetcode2262 字符串的总引力
long long LeetArray::appealSum(std::string s) {
  // ans 20231122
  // 把s[i]添加到以s[i-1]结尾的子数组上
  // 1)
  // 假如s[i]之前没出现过，引力值会增加i（以s[i-1]结尾的子串有i个）,同时要加1，即s[i]单独成串
  // pre += i + 1
  // 2)
  // 假如s[i]之前出现过，最后一个出现的位置为j，引力值只会增加i-j-1（以s[i-1]结尾的子串有i个,
  // 但是前j+1个子串即便加上s[i]引力也不变）,同时要加1，即s[i]单独成串
  // pre += i - (j + 1) + 1
  // pre += i - j
  // 使用一个哈希表记录j
  // 3)
  // 把所有的pre加起来就是结果
  int n = s.length();
  long res = 0L;
  int pre = 0;
  std::vector<int> last(26, -1);
  for (int i = 0; i < n; i++) {
    int cur = s[i] - 'a';
    if (-1 == last[cur]) {
      // 之前没遇到过
      pre += i + 1;
    } else {
      // 之前遇到过
      pre += i - last[cur];
    }
    res += pre;
    last[cur] = i;
  }

  return res;
}

// leetcode828 统计子串中的唯一字符
int LeetArray::uniqueLetterString(std::string s) {
  // ans 20231122
  //  mem1[i]: 以 s[i] 结尾且 s[i] 为唯一字符的子串个数
  //  mem2[i]: 以 s[i] 开始且 s[i] 为唯一字符的子串个数
  //  则以字符 s[i] 为唯一字符的子串个数为 mem1[i] * mem2[i]
  //  举例说明：对于字符串 'cbabcd'
  //  子串 'cba', 'ba', 'a' (3个) 是以 'a' 结尾的子串
  //  子串 'a', 'ab', 'abc', 'abcd' (4个) 是以 'a' 开始的子串
  //  那么以 'a' 为唯一字符的子串为:
  // 'cba', 'cbab', 'cbabc', 'cbabcd'
  // 'ba', 'bab', 'babc', 'babcd'
  // 'a', 'ab', 'abc', 'abcd'
  //  共计 3 * 4 = 12 个

  int n = s.length();
  std::vector<int> mem1(n, -1);
  std::vector<int> mem2(n, -1);

  // pre[s[i]] : 保存字符 s[i] 上一次出现的位置
  // 我们假设字符 s[i] 上一次出现的位置为 pre
  // （如果 字符 s[i] 在位置 i 是第一次出现，我们设 pre = -1）
  // 那么在 闭区间[pre + 1, i] 内的所有以 s[i] 结尾的子串所包含的字符 s[i]
  // 必唯一 共计 i - pre 个
  // nxt[s[i]] : 保存字符 s[i] 下一次出现的位置
  // 我们假设字符 s[i] 下一次出现的位置为 nxt
  // （如果 字符 s[i] 在位置 i 是最后一次出现，我们设 nxt = n）
  // 那么在 闭区间[i, nxt] 内的所有以 s[i] 开始的子串所包含的字符 s[i] 必唯一
  // 共计 nxt - i 个
  // 以字符 s[i] 为唯一字符的子串个数为(i - pre) * (nxt - i)

  std::vector<int> pre(26, -1);  // 默认为 -1
  std::vector<int> last(26, n);  // 默认为 n

  for (int i = 0; i < n; i++) {
    mem1[i] = i - pre[s[i] - 'A'];
    pre[s[i] - 'A'] = i;
  }

  for (int i = n - 1; i >= 0; i--) {
    mem2[i] = last[s[i] - 'A'] - i;
    last[s[i] - 'A'] = i;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += mem1[i] * mem2[i];
  }
  return res;
}

// leetcode2522 将字符串分割成值不超过 K 的子字符串
int LeetArray::minimumPartition(std::string s, int k) {
  // resolve 20231122
  // 枚举每一位，然后保持当前值小于等于K
  int res = 1;
  long x = 0;
  for (char ch : s) {
    int i = ch - '0';
    if (i > k) return -1;
    x = x * 10 + i;
    if (x > k) {
      res++;
      x = i;
    }
  }
  return res;
}

// leetcode2521 数组乘积中的不同质因数数目
int LeetArray::distinctPrimeFactors(std::vector<int>& nums) {
  // ans 20231122
  // 哈希，找每个元素的质数因子，添加到哈希set，哈希set的长度就是答案
  std::unordered_set<int> set;
  for (int n : nums) {
    int i = 2;
    while (i * i <= n) {
      if (0 == n % i) {
        set.insert(i);
        n /= i;
        while (0 == n % i) {
          n /= i;
        }
      }
      i++;
    }
    if (n > 1) set.insert(n);
  }
  return set.size();
}

// leetcode896 单调数列
bool LeetArray::isMonotonic(std::vector<int>& nums) {
#if 0
  // resolve 20231122
  int n = nums.size();
  if (n <= 2) return true;
  for (int i = 1; i < n - 1; i++) {
    int cur = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] == cur) {
      j--;
    }
    if (j < 0) continue;
    int k = i + 1;
    while (k < n && nums[k] == cur) {
      k++;
    }
    if (k == n) return true;
    long pre = nums[j];
    long next = nums[k];
    if ((cur - pre) * (cur - next) > 0) return false;
  }
  return true;
#else
  // resolve 20231122
  bool inc = true;  // 递增
  bool dec = true;  // 递减
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1]) inc = false;
    if (nums[i] > nums[i - 1]) dec = false;
    if (!inc && !dec) return false;
  }
  return true;
#endif
}

// leetcode643 子数组最大平均数I
double LeetArray::findMaxAverage(std::vector<int>& nums, int k) {
  int n = nums.size();
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }
  int res = sum;
  for (int i = k; i < n; i++) {
    sum += nums[i] - nums[i - k];
    res = std::max(res, sum);
  }
  return res / (k * 1.0);
}

// leetcode1763 最长的美好子字符串
std::string LeetArray::longestNiceSubstring(std::string s) {
  if (s.size() < 2) return "";
  int n = s.size();
  int lower[26];
  int upper[26];
  memset(lower, 0, sizeof(lower));
  memset(upper, 0, sizeof(upper));
  for (char c : s) {
    if (c >= 'a' && c <= 'z') lower[c - 'a']++;
    if (c >= 'A' && c <= 'Z') upper[c - 'A']++;
  }

  for (int i = 0; i < n; i++) {
    char c = s[i];
    int idx;
    if (c >= 'a' && c <= 'z') idx = c - 'a';
    if (c >= 'A' && c <= 'Z') idx = c - 'A';
    if (!lower[idx] || !upper[idx]) {
      auto res1 = longestNiceSubstring(s.substr(0, i));
      auto res2 = longestNiceSubstring(s.substr(i + 1, n - i));
      return res1.size() < res2.size() ? res2 : res1;
    }
  }

  return s;
}

// leetcode1876 长度为三且各字符不同的子字符串
int LeetArray::countGoodSubstrings(std::string s) {
  int n = s.size();
  if (n < 3) return 0;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));

  bool repeat = false;
  for (int i = 0; i < 3; i++) {
    int idx = s[i] - 'a';
    if (cnt[idx] > 0) repeat = true;
    cnt[idx]++;
  }

  int res = 0;
  if (!repeat) res++;
  for (int i = 1; i < n - 2; i++) {
    int idx1 = s[i - 1] - 'a';
    int idx2 = s[i] - 'a';
    int idx3 = s[i + 1] - 'a';
    int idx4 = s[i + 2] - 'a';

    cnt[idx1]--;
    cnt[idx4]++;
    if (1 == cnt[idx4] && 1 == cnt[idx2] && 1 == cnt[idx3]) {
      res++;
    }
  }
  return res;
}

// leetcode485 最大连续 1 的个数
int LeetArray::findMaxConsecutiveOnes(std::vector<int>& nums) {
  // resolve 20231126
  int n = nums.size();
  int l = 0;
  int r = 0;
  int res = 0;
  while (l < n && r < n) {
    while (l < n && 1 != nums[l]) {
      l++;
    }
    r = l;
    while (r < n && 1 == nums[r]) {
      r++;
    }
    res = std::max(res, r - l);
    l = r;
  }
  return res;
}

/*
int minimumDifference(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int n = nums.size();
  int res = INT_MAX;
  for (int i = 0; i < n - k + 1; i++) {
    res = std::min(res, nums[i + k - 1] - nums[i]);
  }
  return res;
}
*/

// leetcode2515 <==> leetcode2516 <==> leetcode2517 <==> leetcode2518
// leetcode2515 到目标字符串的最短距离
int LeetArray::closetTarget(std::vector<std::string>& words, std::string target,
                            int startIndex) {
  // resolve 20231125
  int n = words.size();
  int i = 0;
  int res = INT_MAX;
  while (i < n) {
    if (target == words[i]) {
      int dist = std::abs(i - startIndex);
      int cur = std::min(dist, n - dist);
      res = std::min(res, cur);
    }
  }
  return res;
}

// leetcode2515 <==> leetcode2516 <==> leetcode2517 <==> leetcode2518
// leetcode2516 每种字符至少取K个
int LeetArray::takeCharacters(std::string s, int k) {
#if 0
  // ans 20231125
  int n = s.size();
  if (n < 3 * k) return -1;

  // 1、前缀为空，遍历后缀
  int cnt[3] = {0, 0, 0};
  int j = n;
  while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
    if (j == 0) return -1;
    j--;
    cnt[s[j] - 'a']++;
  }

  // 2、枚举前缀，优化后缀
  int res = n - j;  // res 不大于n
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
    while (j < n && cnt[s[j] - 'a'] > k) {
      cnt[s[j] - 'a']--;
      j++;
    }
    res = std::min(res, i + 1 + n - j);
    if (j == n) break;  // 剪枝，后缀无法再继续更新
  }
  return res;
#else
  // ans 20231125
  // 二分
  int n = s.size();
  if (n < 3 * k) return -1;

  std::function<bool(int)> f = [&](int idx) -> bool {
    int cnt[3] = {0};
    int i = 0;
    while (i < idx) {
      cnt[s[i] - 'a']++;
      i++;
    }
    if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) return true;
    i = 1;
    while (i <= idx) {
      cnt[s[idx - i] - 'a']--;
      cnt[s[n - i] - 'a']++;
      if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) return true;
      i++;
    }
    return false;
  };

  int l = 0, r = n - 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }

  return l;
#endif
}

// leetcode2515 <==> leetcode2516 <==> leetcode2517 <==> leetcode2518
// leetcode2517 礼盒的最大甜蜜度
int LeetArray::maximumTastiness(std::vector<int>& price, int k) {
  // ans 20231125
  // 二分
  std::sort(price.begin(), price.end());
  int n = price.size();

  // 测试当前甜蜜度满不满足要求
  std::function<bool(int)> f = [&](int d) -> bool {
    int cnt = 1;
    int cur = price[0];
    for (auto p : price) {
      if (p - cur >= d) {
        cnt++;
        cur = p;
      }
    }
    return cnt >= k;
  };

  int l = 0, r = (price[n - 1] - price[0]) / (k - 1) + 1;
  while (l < r - 1) {
    int mid = l + (r - l) / 2;
    if (f(mid))
      l = mid;
    else
      r = mid;
  }

  return l;
}

// leetcode2515 <==> leetcode2516 <==> leetcode2517 <==> leetcode2518
// leetcode2518 好分区的数目
int LeetArray::countPartitions(std::vector<int>& nums, int k) {
  // ans 20231127
  // 将问题转换成找坏分区
  if (accumulate(nums.begin(), nums.end(), 0L) < k * 2) return 0;
  const int MOD = 1e9 + 7;
  int ans = 1;
  std::vector<int> f(k, 0);
  f[0] = 1;
  for (int x : nums) {
    ans = ans * 2 % MOD;
    for (int j = k - 1; j >= x; --j) f[j] = (f[j] + f[j - x]) % MOD;
  }
  for (int x : f) ans = (ans - x * 2 % MOD + MOD) % MOD;  // 保证答案非负
  return ans;
}

// leetcode2486 追加字符以获得子序列
int LeetArray::appendCharacters(string s, string t) {
  // resolve 20231130
  // 因为i只有可能被从0到n加一次，所以时间复杂度是O(n)
  int n = s.size();
  int m = t.size();
  int i = 0;
  for (int j = 0; j < m; j++) {
    char ch = t[j];
    while (i < n && s[i] != ch) {
      i++;
    }
    if (i == n) return m - j;
    i++;
  }
  return 0;
}

// leetcode2488 统计中位数为 K 的子数组
int LeetArray::countSubarrays(vector<int>& nums, int k) {
  // ans 20231130
  // model
  int n = nums.size();
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (k == nums[i]) {
      idx = i;
      break;
    }
  }
  std::unordered_map<int, int> count;
  count[0]++;
  for (int i = idx + 1, x = 0; i < n; i++) {
    x += nums[i] > k ? 1 : -1;
    count[x]++;
  }
  int res = 0;
  res += count[0] + count[1];
  for (int i = idx - 1, x = 0; i >= 0; i--) {
    x += nums[i] > k ? -1 : 1;
    res += count[x] + count[x + 1];
  }
  return res;
}

// leetcode2337 移动片段得到字符串
bool LeetArray::canChange(string start, string target) {
  auto s = start, t = target;
  s.erase(remove(s.begin(), s.end(), '_'), s.end());
  t.erase(remove(t.begin(), t.end(), '_'), t.end());
  if (s != t) return false;

  int n = start.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    if ('_' == start[i]) continue;
    while ('_' == target[j]) j++;
    if (start[i] == 'L') {
      if (i < j) return false;
    } else {
      if (i > j) return false;
    }
    j++;
  }
  return true;
}

int findJudge(int n, vector<vector<int>>& trust) {
#if 0
  // resolve 20231201
  // 出现在第一个位置就不是法官（是市民），出现在第二个位置，则统计信任此人的数量（假如不是市民）
  std::vector<bool> citizen(n, false);
  std::vector<int> cnt(n, 0);
  for (auto t : trust) {
    citizen[t[0] - 1] = true;
    if (false == citizen[t[1] - 1]) cnt[t[1] - 1]++;
  }

  for (int i = 0; i < n; i++) {
    if (false == citizen[i] && n - 1 == cnt[i]) return i + 1;
  }
  return -1;
#else
  // resolve 20231201
  // 入度
  std::vector<int> cnt(n, 0);
  for (auto t : trust) {
    cnt[t[0] - 1]--;  // 信任别人入度减一
    cnt[t[1] - 1]++;  // 被信任入度加一
  }
  // 法官的入度为n-1
  for (int i = 0; i < n; i++) {
    if (n - 1 == cnt[i]) return i + 1;
  }
  return -1;
#endif
}

// leetcode2865 美丽塔I
long long LeetArray::maximumSumOfHeights(vector<int>& a) {
  long res = LONG_MIN;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int x = a[i];
    long s = x;

    int min_cur = x;
    int j = i - 1;
    while (j >= 0) {
      min_cur = std::min(a[j], min_cur);
      s += min_cur;
      j--;
    }
    min_cur = x;
    j = i + 1;
    while (j < n) {
      min_cur = std::min(a[j], min_cur);
      s += min_cur;
      j++;
    }
    res = std::max(res, s);
  }
  return res;
}

// leetcode2815 数组中的最大数对和
int LeetArray::maxSum(vector<int>& nums) {
  int res = -1;
  vector<int> max_val(10, INT_MIN);
  std::function<int(int)> f = [&](int num) -> int {
    int v = 0;
    while (num > 0) {
      v = max(num % 10, v);
      num /= 10;
    }
    return v;
  };
  for (int x : nums) {
    int max_d = f(x);
    res = max(res, max_val[max_d] + x);
    max_val[max_d] = max(max_val[max_d], x);
  }
  return res;
}

// leetcode2817 限制条件下元素之间的最小绝对差
int minAbsoluteDifference(vector<int>& nums, int x) {
  int res = INT_MAX, n = nums.size();
  std::set<int> s = {INT_MIN / 2, INT_MAX};
  for (int i = x; i < n; i++) {
    s.insert(nums[i - x]);
    int y = nums[i];
    auto it = s.lower_bound(y);
    res = min(res, min(*it - y, y - *prev(it)));
  }
  return res;
}

}  // namespace myleet