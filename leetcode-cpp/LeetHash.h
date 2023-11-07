#ifndef __LEET_HASH_H__
#define __LEET_HASH_H__

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
  // leetcode141 环形链表
  static bool hasCycle(ListNode *head);
  // leetcode160 相交链表
  static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
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
  std::string mostCommonWord(std::string paragraph,
                             std::vector<std::string> &banned);
  // leetcode859 亲密字符串
  bool buddyStrings(std::string s, std::string goal);
  // leetcode884 两句话中的不常见单词
  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2);
  // leetcode914 卡牌分组
  bool hasGroupsSizeX(std::vector<int> &deck);
  // leetcode929 独特的邮件地址
  int numUniqueEmails(std::vector<std::string> &emails);
  // leetcode953 验证外星语词典
  bool isAlienSorted(std::vector<std::string> &words, std::string order);
  // leetcode961 在长度 2N 的数组中找出重复 N 次的元素
  int repeatedNTimes(std::vector<int> &nums);
  // leetcode1160 拼写单词
  int countCharacters(std::vector<std::string> &words, std::string chars);
};

}  // namespace myleet

#endif