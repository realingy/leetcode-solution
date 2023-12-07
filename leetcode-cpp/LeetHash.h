#ifndef __LEET_HASH_H__
#define __LEET_HASH_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetHash {
 public:
  LeetHash() {}
  ~LeetHash() {}

 public:
  static int romanToInt(std::string s);
  // leetcode169 多数元素
  static int majorityElement(std::vector<int> &nums);
  // leetcode383 赎金信
  static bool canConstruct(std::string ransomNote, std::string magazine);
  // leetcode387 字符串中的第一个唯一字符
  static int firstUniqChar(std::string s);
  // leetcode448 找到所有数组中消失的数字
  static std::vector<int> findDisappearedNumbers(std::vector<int> &nums);
  // leetcode496 下一个更大元素I
  static std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                             std::vector<int> &nums2);
  // leetcode575 分糖果
  static int distributeCandies(std::vector<int> &candyType);
  // leetcode645 错误的集合
  static std::vector<int> findErrorNums(std::vector<int> &nums);
  // leetcode697 数组的度
  static int findShortestSubArray(std::vector<int> &nums);
  // leetcode819 最常见的单词
  static std::string mostCommonWord(std::string paragraph,
                                    std::vector<std::string> &banned);
  // leetcode859 亲密字符串
  static bool buddyStrings(std::string s, std::string goal);
  // leetcode884 两句话中的不常见单词
  static std::vector<std::string> uncommonFromSentences(std::string s1,
                                                        std::string s2);
  // leetcode914 卡牌分组
  static bool hasGroupsSizeX(std::vector<int> &deck);
  // leetcode929 独特的邮件地址
  static int numUniqueEmails(std::vector<std::string> &emails);
  // leetcode953 验证外星语词典
  static bool isAlienSorted(std::vector<std::string> &words, std::string order);
  // leetcode961 在长度 2N 的数组中找出重复 N 次的元素
  static int repeatedNTimes(std::vector<int> &nums);
  // leetcode1160 拼写单词
  static int countCharacters(std::vector<std::string> &words,
                             std::string chars);
  // leetcode1189 “气球” 的最大数量
  static int maxNumberOfBalloons(std::string text);
  // leetcode2933 高访问员工
  static std::vector<std::string> findHighAccessEmployees(
      std::vector<std::vector<std::string>> &access_times);
  // leetcode2451 差值数组不同的字符串
  static string oddString(vector<string> &words) {
    // resolve 20231207 哈希
    map<vector<int>, vector<string>> count;
    int n = words[0].size();
    for (auto &s : words) {
      vector<int> cut;
      for (int i = 1; i < n; i++) cut.emplace_back(s[i] - s[i - 1]);
      count[cut].push_back(s);
    }
    for (auto it = count.begin(); it != count.end(); it++)
      if (it->second.size() == 1) return (it->second)[0];
    return "";
  }
  // leetcode2453 摧毁一系列目标
  int destroyTargets(vector<int> &nums, int space) {
    // resolve 20231207 哈希
    unordered_map<int, int> cnt;
    for (auto n : nums) {
      cnt[n % space]++;
    }
    int res = nums[0];
    int mx = INT_MIN;
    for (auto n : nums) {
      int c = cnt[n % space];
      if (c == mx) {
        res = min(res, n);
      } else if (c > mx) {
        mx = c;
        res = n;
      }
    }
    return res;
  }
};

}  // namespace myleet

#endif