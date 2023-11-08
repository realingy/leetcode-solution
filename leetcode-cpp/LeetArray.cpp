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

}  // namespace myleet