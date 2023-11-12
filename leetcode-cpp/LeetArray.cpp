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

}  // namespace myleet