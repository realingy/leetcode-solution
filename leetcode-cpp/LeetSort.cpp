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
  // ans
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
  // 创建辅助数组放奇数
  int n = (int)nums.size();
  int i = 0;
  int j = n - 1;

#endif
}

}  // namespace myleet
