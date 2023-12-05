#ifndef __LEETSTRING_H__
#define __LEETSTRING_H__

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetString {
 public:
  LeetString() {}
  ~LeetString() {}

 public:
  // leetcode3 最长无重复字符子串
  static int lengthOfLongestSubstring(std::string s);
  // leetcode20 合理的括号
  static bool isValid(std::string s);
  // leetcode28 匹配子串
  static int strStr(std::string haystack, std::string needle);
  // leetcode205 同构字符串
  static bool isIsomorphic(std::string s, std::string t);
  // leetcode244 反转字符串
  static void reverseString(std::vector<char>& s);
  //
  static std::string reverseVowels(std::string s);
  // leetcode409 最长回文长度
  static int longestPalindrome(std::string s);
  // leetcode419 FizzBuzz
  static std::vector<std::string> fizzBuzz(int n);
  // leetcode415 字符串相加
  static std::string addStrings(std::string num1, std::string num2);
  // leetcode434 单词数
  static int countSegments(std::string s);
  // leetcode459 重复的子串
  static bool repeatedSubstringPattern(std::string s);
  // leetcode482 格式化密码
  static std::string licenseKeyFormatting(std::string s, int k);
  // leetcode500 键盘行
  static std::vector<std::string> findWords(std::vector<std::string>& words);
  // leetcode520 单词合理性
  static bool detectCapitalUse(std::string word);
  // leetcode521 最长特殊子串
  static int findLUSlength(std::string a, std::string b);
  // leetcode541 反转字符串
  static std::string reverseStr(std::string s, int k);
  // leetcode551 出勤
  static bool checkRecord(std::string s);
  // leetcode557 反转单词
  static std::string reverseWords(std::string s);
  // leetcode557 共同喜欢的餐厅，最小index和
  static std::vector<std::string> findRestaurant(
      std::vector<std::string>& list1, std::vector<std::string>& list2);
  // leetcode657 回到原点
  static bool judgeCircle(std::string moves);
  // leetcode680 验证回文（最多可以删除一个字符,顺序不改）
  static bool validPalindrome(std::string s);
  // leetcode696 计数二进制子串
  static int countBinarySubstrings(std::string s);
  // leetcode709 转换成小写字母
  static std::string toLowerCase(std::string s);
  // leetcode748 最短补全词
  static std::string shortestCompletingWord(std::string licensePlate,
                                            std::vector<std::string>& words);
  // leetcode771 宝石数量
  static int numJewelsInStones(std::string jewels, std::string stones);
  // leetcode796 旋转字符串
  static bool rotateString(std::string s, std::string goal);
  // leetcode804 唯一摩斯密码
  static int uniqueMorseRepresentations(std::vector<std::string>& words);
  // leetcode806 写字符串需要的行
  static std::vector<int> numberOfLines(std::vector<int>& widths,
                                        std::string s);
  // leetcode819 出现次数最多单词
  static std::string mostCommonWord(std::string paragraph,
                                    std::vector<std::string>& banned);
  // leetcode821 最短距离
  static std::vector<int> shortestToChar(std::string s, char c);
  // leetcode824 山羊拉丁文
  static std::string toGoatLatin(std::string sentence);
  // leetcode830 较大分组的位置
  static std::vector<std::vector<int>> largeGroupPositions(std::string s);
  // leetcode844 比较含退格的字符串
  static bool backspaceCompare(std::string s, std::string t);
  // leetcode925 长按键入
  static bool isLongPressedName(std::string name, std::string typed);
  // leetcode942 增减字符串匹配
  std::vector<int> diStringMatch(std::string s);
  // leetcode944 删列造序
  static int minDeletionSize(std::vector<std::string>& strs);
  // leetcode1071 字符串的最大公因子
  static std::string gcdOfStrings(std::string str1, std::string str2);
  // leetcode1078 Bigram 分词
  static std::vector<std::string> findOcurrences(std::string text,
                                                 std::string first,
                                                 std::string second);
  // leetcode1108 IP 地址无效化
  static std::string defangIPaddr(std::string address);
  // leetcode1154 一年中的第几天
  static int dayOfYear(std::string date);
  // leetcode5 最长回文
  static std::string longestPalindrome5(std::string s);
  // leetcode6 N字形变换
  static std::string convert(std::string s, int numRows);
  // leetcode8 字符串转换整数(atoi)
  static int myAtoi(std::string str);
  // leetcode2255 统计是给定字符串前缀的字符串数目
  int countPrefixes(vector<string>& words, string s) {
    int n = words.size();
    int res = 0;
    for (string word : words) {
      res += (0 == s.find(word));
    }
    return res;
  }

  // leetcode1374 生成每种字符都是奇数个的字符串
  string generateTheString(int n) {
    if (!(n % 2))
      return 'a' + string(n - 1, 'b');
    else
      return string(n, 'a');
  }

  // leetcode1408 数组中的字符串匹配
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i != j && words[j].find(words[i]) != -1) {
          ans.emplace_back(move(words[i]));
          break;
        }
      }
    }
    return ans;
  }

  // leetcode1528 重新排列字符串
  string restoreString(string s, vector<int>& indices) {
    int n = s.size();
    string res = s;
    for (int i = 0; i < n; i++) {
      res[indices[i]] = s[i];
    }
    return res;
  }

  // leetcode1598 文件夹操作日志搜集器
  int minOperations(vector<string>& logs) {
    int depth = 0;
    for (string log : logs) {
      if ("../" == log)
        depth = max(depth - 1, 0);
      else if ("./" != log)
        depth++;
    }
    return depth;
  }

  // leetcode1629 按键持续时间最长的键
  char slowestKey(vector<int>& t, string k) {
    int n = t.size();
    int max = INT_MIN;
    int idx = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (i > 0) t[i] -= t[i - 1];
      if (t[i] > max) {
        max = t[i];
        idx = i;
      } else if (t[i] == max && k[i] > k[idx]) {
        idx = i;
      }
    }
    return k[idx];
  }

  // leetcode1816 截断句子
  string truncateSentence(string s, int k) {
    int i = 0;
    int n = s.size();
    while (i < n) {
      if (s[i] == ' ') k--;
      if (!k) break;
      i++;
    }
    return s.substr(0, i);
  }

  // leetcode1961 检查字符串是否为数组前缀
  bool isPrefixString(string s, vector<string>& words) {
    string tmp = "";
    int i = 0;

    while (i < words.size() && tmp.size() < s.size()) tmp += words[i++];
    return tmp == s;
  }

  // leetcode2734 执行子串操作后的字典序最小字符串
  string smallestString(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] > 'a') {
        for (; i < n && s[i] > 'a'; i++) {
          s[i]--;
        }
        return s;
      }
    }
    s[n - 1] = 'z';
    return s;
  }

  // leetcode2108 找出数组中的第一个回文字符串
  string firstPalindrome(vector<string>& words) {
    for (string word : words) {
      auto src = word;
      reverse(word.begin(), word.end());
      if (src == word) return src;
    }
    return "";
  }

  // leetcode2114 句子中的最多单词数
  static int mostWordsFound(vector<string>& s) {
    int res = 0;
    for (string x : s) {
      int c = std::count(x.begin(), x.end(), ' ') + 1;
      res = max(res, c);
    }
    return res;
  }

  int prefixCount(vector<string>& words, string pref) {
    int res = 0;
    // int n = pref.size();
    for (string x : words) {
      // res += x.substr(0, n) == pref;
      res += x.find(pref) == 0;
    }
    return res;
  }
};

}  // namespace myleet

#endif