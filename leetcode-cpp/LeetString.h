#ifndef __LEETSTRING_H__
#define __LEETSTRING_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

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
};

}  // namespace myleet

#endif