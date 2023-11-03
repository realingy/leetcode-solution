#include <iostream>
#include <vector>

#include "LeetSort.h"
#include "LeetString.h"

using namespace myleet;

void ProcessString();
void ProcessSort();

int main() {
  std::cout << "type: " << std::endl;
  std::cout << "index: " << std::endl;

  // ProcessString();
  ProcessSort();

  return 0;
}

// LeetString 字符串操作
void ProcessString() {
  // leet3
  if (0) {
    std::string str = "abcabc";
    // 最大无重复字符子串长度
    int len = LeetString::lengthOfLongestSubstring(str);
    std::cout << "len: " << len << std::endl;
  }

  // leet20
  if (0) {
    std::string str = "({})";
    bool valid = LeetString::isValid(str);
    std::cout << "valid: " << valid << std::endl;

    str = "(})";
    valid = LeetString::isValid(str);
    std::cout << "valid: " << valid << std::endl;
  }

  // leet28
  if (0) {
    LeetString::strStr("scddaabaaabsdfaabaaab", "aabaaab");
  }

  // leet205
  if (0) {
    bool same = LeetString::isIsomorphic("abb", "bhh");
    if (same) {
      std::cout << "some " << std::endl;
    } else {
      std::cout << "not some " << std::endl;
    }
  }

  if (0) {
    std::vector<char> arr;
    arr.emplace_back('a');
    arr.emplace_back('s');
    arr.emplace_back('d');
    // arr.emplace_back('f');
    LeetString::reverseString(arr);
    for (int i = 0; i < arr.size(); i++) {
      std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
  }

  if (0) {
    std::string str = LeetString::reverseVowels("heEllo");
    std::cout << "new str: " << str << std::endl;
  }

  if (0) {
    int len = LeetString::longestPalindrome("ccc");
  }

  if (0) {
    std::vector<std::string> fiz = LeetString::fizzBuzz(5);
  }

  if (0) {
    std::string str = LeetString::addStrings("143", "75");
    std::cout << "str: " << str << std::endl;
  }

  if (0) {
    // leetcode459 重复的子串
    // bool ret = LeetString::repeatedSubstringPattern("abcabcabcabc");
    bool ret = LeetString::repeatedSubstringPattern("abaababaab");
    std::cout << "rtepeat: " << ret << std::endl;
  }

  if (0) {
    // std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
    std::vector<std::string> words = {"omk"};
    std::vector<std::string> ans = LeetString::findWords(words);
    for (int i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << ", ";
    }
    std::cout << std::endl;
  }

  if (0) {
    // std::string res = LeetString::reverseStr("abcdefg", 8);
    std::string res = LeetString::reverseStr("abcdefg", 4);
    // std::string res = LeetString::reverseStr(
    // "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdao"
    // "vjgunjqlimjkfnqcqnajmebeddqsgl",
    // 39);
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string res = LeetString::reverseWords("Let's take LeetCode contest");
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string s =
        "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpf"
        "dhooxfuupuculmgmqfvnbgtapekouga";
    bool res = LeetString::validPalindrome(s);
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    int res = LeetString::countBinarySubstrings("00110011");
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string res = LeetString::toLowerCase("Hello");
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string jewels = "z";
    std::string stones = "aAAbd";
    int res = LeetString::numJewelsInStones(jewels, stones);
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string sentence = "I speak Goat Latin";
    std::string res = LeetString::toGoatLatin(sentence);
    std::cout << "res: " << res << std::endl;
  }

  std::cout << "end.........\n";
}

// LeetSort 排序操作
void ProcessSort() {
  if (0) {
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = LeetSort::majorityElement(nums);
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::string s = "anagram";
    std::string t = "nagaram";
    bool res = LeetSort::isAnagram(s, t);
    std::cout << "res: " << res << std::endl;
  }

  if (0) {
    std::vector<int> score = {5, 4, 3, 2, 1};
    std::vector<std::string> res = LeetSort::findRelativeRanks(score);
    for (std::string r : res) {
      std::cout << r << ", ";
    }
    std::cout << "\n";
  }

  if (0) {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    int res = LeetSort::findLHS(nums);
    std::cout << "res: " << res << "\n";
  }

  if (0) {
    std::vector<int> nums = {2, 3, 1, 4};
    std::vector<int> res = LeetSort::sortArrayByParityII(nums);
    std::cout << "res: " << res.size() << "\n";
  }

  if (1) {
    std::vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    std::vector<int> res = LeetSort::arrayRankTransform(arr);
  }
}
