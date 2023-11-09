#include "LeetString.h"

#include <iostream>
#include <map>
#include <unordered_map>

namespace myleet {

// leetcode3最长无重复字符子串
int LeetString::lengthOfLongestSubstring(std::string s) {
  int m[256] = {0};
  int n = s.size();
  int res = 0, left = 0;
  for (int i = 0; i < n; i++) {
    if (m[s[i]] == 0 || m[s[i]] < left) {
      // res = max(res, i - left + 1);
      if ((i - left + 1) > res) {
        res = i - left + 1;
      }
    } else {
      left = m[s[i]];
    }
    m[s[i]] = i + 1;
  }

  return res;
}

// leet20 合理的括号
bool LeetString::isValid(std::string s) {
  if (s.size() % 2) return false;

  std::vector<char> stack;
  for (int i = 0; i < s.size(); i++) {
    if ('(' == s[i])
      stack.emplace_back(')');
    else if ('[' == s[i])
      stack.emplace_back(']');
    else if ('{' == s[i])
      stack.emplace_back('}');
    else if (!stack.size())
      return false;
    else if (s[i] != stack[stack.size() - 1])
      return false;
    else
      stack.pop_back();
  }

  return stack.empty();
}

void genNext(const std::string &needle, std::vector<int> &next) {
  int n = needle.size();
  next.resize(n);
  next[0] = 0;
  for (int l = 0, r = 1; r < n; r++) {
    while (l > 0 && needle[l] != needle[r]) l = next[l - 1];
    if (needle[l] == needle[r]) l++;
    next[r] = l;
  }
}

// leetcode28 匹配子串
int LeetString::strStr(std::string haystack, std::string needle) {
  int type = 1;
  // 暴力法
  if (0 == type) {
    int ret = -1;
    int m = needle.size();
    int n = haystack.size();

    for (int i = 0; i < n; i++) {
      // std::string cur = haystack.substr(i, len);
      // if (needle == cur) {
      // ret = i;
      // break;
      // }
      bool match = true;
      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          match = false;
          break;
        }
      }

      if (true == match) {
        ret = i;
        break;
      }
    }

    return ret;
  } else if (1 == type) {
    // KMP算法
    std::string str = needle;
    std::vector<int> arr;
    genNext(str, arr);
    /*
    for (int i = 0; i < arr.size() - 1; i++) {
      std::cout << arr[i] << ",";
    }
    std::cout << arr[arr.size() - 1] << std::endl;
    */
    int n = haystack.size();
    int m = needle.size();
    for (int i = 0, j = 0; i < n; i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = arr[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == m) {
        return i - m + 1;
      }
    }

    return -1;
  }
}

// leetcode205 同构字符串
bool LeetString::isIsomorphic(std::string s, std::string t) {
  int type = 1;
  if (0 == type) {
    // 20231020
    // 思路：两个字符数组直接相减（string看成char的数组）,得到一个int的数组arr，然后遍历s和arr，
    // s中相等的字符对应的arr数字应该也相等
    if (s.size() != t.size()) return false;
    bool ret = true;
    int n = s.size();
    std::vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
      arr1[i] = t[i] - s[i];
    }

    for (int i = 0; i < n; i++) {
      std::cout << arr1[i] << ",";
    }

    std::cout << std::endl;

    return ret;
  } else if (1 == type) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    std::unordered_map<char, char> map1;
    std::unordered_map<char, char> map2;

    for (int i = 0; i < n; i++) {
      if (map1.find(s[i]) != map1.end() || map2.find(t[i]) != map2.end()) {
        if (map1[s[i]] != t[i] || map2[t[i]] != s[i]) return false;
      } else {
        map1[s[i]] = t[i];
        map2[t[i]] = s[i];
      }
    }

    return true;
  }
}

// leetcode244 反转字符串
void LeetString::reverseString(std::vector<char> &s) {
  // 思路：两两对调
  int n = s.size();
  for (int i = 0; i < s.size() / 2; i++) {
    char temp = s[i];
    char l = s[n - 1 - i];
    s[i] = l;
    s[n - 1 - i] = temp;
  }
}

std::string LeetString::reverseVowels(std::string s) {
  // 20231020
  std::string t(s);
  int n = s.size();
  std::vector<int> index;
  std::vector<char> arr;
  for (int i = 0; i < n; i++) {
    char cur = s[i];
    if ('a' == cur || 'e' == cur || 'o' == cur || 'i' == cur || 'u' == cur ||
        'A' == cur || 'E' == cur || 'I' == cur || 'O' == cur || 'U' == cur) {
      index.emplace_back(i);
      arr.emplace_back(s[i]);
    }
  }

  int m = index.size();
  for (int i = 0; i < m; i++) {
    int idx = index[i];
    t[idx] = arr[m - 1 - i];
  }

  return t;
}

// leetcode409 最长回文长度
int LeetString::longestPalindrome(std::string s) {
  // ans 20231031
  int count[128] = {0};
  int length = s.size();
  for (int i = 0; i < length; ++i) {
    char c = s[i];
    count[c]++;
  }

  int len = 0;
  for (int i = 0; i < 128; ++i) {
    int c = count[i];
    // if (c > 0) {
    // std::cout << "xxx: " << c << std::endl;
    // }
    len += 2 * (c / 2);
    // 没有单独字母的最长回文的长度肯定是复数,遇到第一个单独字母且回文长度为偶数把这个单独字母放进去，之后不再加单独字母
    if ((c % 2) && !(len % 2)) len++;
  }

  // std::cout << "22222222222222: " << len << std::endl;
  return len;
}

// leetcode419 Fizz Buzz
std::vector<std::string> LeetString::fizzBuzz(int n) {
  std::vector<std::string> ret;
  for (int i = 1; i <= n; i++) {
    // 3的倍数
    if (!(i % 3) && (i % 5)) {
      ret.emplace_back("Fizz");
    } else if ((i % 3) && !(i % 5)) {
      ret.emplace_back("Buzz");
    } else if (!(i % 3) && !(i % 5)) {
      ret.emplace_back("FizzBuzz");
    } else {
      ret.emplace_back(std::to_string(i));
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << ret[i] << " ";
  }
  std::cout << std::endl;

  return ret;
}

std::string LeetString::addStrings(std::string num1, std::string num2) {
  std::string ret;
  int i = num1.size() - 1;
  int j = num2.size() - 1;
  for (int carry = 0; i >= 0 || j >= 0 || carry > 0; i--, j--) {
    int n1 = 0;
    int n2 = 0;
    // std::cout << "i: " << i << ", num1: " << num1[i] << "\n";
    // std::cout << "j: " << j << ", num2: " << num2[j] << "\n";
    if (i >= 0) {
      n1 = num1[i] - '0';
    }
    if (j >= 0) {
      n2 = num2[j] - '0';
    }
    carry += n1 + n2;
    ret += std::to_string(carry % 10);
    carry /= 10;
  }

  // std::cout << std::endl;
  std::string new_ret;
  for (int i = ret.size() - 1; i >= 0; i--) {
    new_ret += ret[i];
  }

  return new_ret;
}

// leetcode434 单词数
int LeetString::countSegments(std::string s) {
  // 双指针
  // 自己完成
  int n = (int)s.size();
  int res = 0;

  int l = 0;
  while (l < n && s[l] == ' ') {
    l++;
  }

  int r = l;
  while (r < n) {
    if (s[r] != ' ') {
      r++;
    } else {
      res++;
      while (r < n && s[r] == ' ') {
        r++;
      }
      l = r;
    }
  }

  res += (l < r);

  return res;
}

// leetcode459 重复的子串
bool LeetString::repeatedSubstringPattern(std::string s) {
  int n = s.size();
  for (int i = 1; i * 2 <= n; ++i) {
    if (n % i == 0) {
      bool match = true;
      for (int j = i; j < n; ++j) {
        if (s[j] != s[j - i]) {
          match = false;
          break;
        }
      }
      if (match) {
        return true;
      }
    }
  }
  return false;
}

std::string LeetString::licenseKeyFormatting(std::string s, int k) {
  std::string ans;
  int t = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '-') {
      ans.push_back(toupper(s[i]));
      t++;
      if (t == k) {
        ans.push_back('-');
        t = 0;
      }
    }
  }
  if (ans.size() && ans.back() == '-') ans.pop_back();
  reverse(ans.begin(), ans.end());
  return ans;
}

// leetcode500 键盘行
std::vector<std::string> LeetString::findWords(
    std::vector<std::string> &words) {
  // resolve 20231101
  std::string charType = "12210111011122000010020202";
  std::vector<std::string> ans;

  for (int i = 0; i < words.size(); i++) {
    std::string word = words[i];
    int idx;
    if (word[0] >= 'A' && word[0] <= 'Z') {
      idx = word[0] - 'A';
    }
    if (word[0] >= 'a' && word[0] <= 'z') {
      idx = word[0] - 'a';
    }
    char type = charType[idx];
    bool match = true;
    for (int j = 0; j < word.size(); j++) {
      // int idx_cur = word[j] - 'a';
      int idx_cur;
      if (word[j] >= 'A' && word[j] <= 'Z') {
        idx_cur = word[j] - 'A';
      }
      if (word[j] >= 'a' && word[j] <= 'z') {
        idx_cur = word[j] - 'a';
      }
      char type_cur = charType[idx_cur];
      std::cout << "char: " << word[j] << ", ";
      std::cout << "idx_cur: " << idx_cur << ", ";
      std::cout << "type_cur: " << type_cur << std::endl;
      if (type_cur != type) {
        match = false;
        break;
      }
    }
    if (true == match) {
      ans.emplace_back(word);
    }
  }

  return ans;
}

// leetcode520 单词合理性
bool LeetString::detectCapitalUse(std::string word) {
  // 自己完成
  int len = (int)word.size();

  if (word[0] >= 'a' && word[0] <= 'z') {
    if (len <= 1) return true;
    for (int i = 1; i < len; i++) {
      if (word[i] >= 'A' && word[i] <= 'Z') {
        return false;
      }
    }
  } else if (word[0] >= 'A' && word[0] <= 'Z') {
    if (len <= 2) return true;
    int type;
    if (word[1] >= 'A' && word[1] <= 'Z') {
      type = 0;
    } else if (word[1] >= 'a' && word[1] <= 'a') {
      type = 1;
    }

    for (int i = 2; i < len; i++) {
      int type_cur;
      if (word[i] >= 'A' && word[i] <= 'Z') {
        type_cur = 0;
        if (type_cur != type) return false;
      } else if (word[i] >= 'a' && word[i] <= 'z') {
        type_cur = 1;
        if (type_cur != type) return false;
      }
    }
  }

  return true;
}

// leetcode521 最长特殊子串
int LeetString::findLUSlength(std::string a, std::string b) {
  // ?????????? 沙雕题目
  // 自己完成
  if (a == b) return -1;
  if (a.size() > b.size())
    return a.size();
  else
    return b.size();
}

// leetcode541 反转字符串
std::string LeetString::reverseStr(std::string s, int k) {
  // 答案
  for (int i = 0; i < s.size(); i += (2 * k)) {
    if (i + k <= s.size()) {
      reverse(s.begin() + i, s.begin() + i + k);
      continue;
    }
    reverse(s.begin() + i, s.begin() + s.size());
  }
  return s;
}

// leetcode551 出勤
bool LeetString::checkRecord(std::string s) {
  // 答案
  // 不能A两次及以上
  // 不能连续L三次及以上
  return s.find('A', s.find('A') + 1) == -1 && s.find("LLL") == -1;
}

// leetcode557 反转单词
std::string LeetString::reverseWords(std::string s) {
  // 双指针
  // resolve 20231101
  int n = (int)s.size();
  std::string res;

  int l = 0;
  while (l < n && s[l] == ' ') {
    l++;
  }

  std::vector<std::string> words;
  int r = l;
  while (r < n) {
    if (s[r] != ' ') {
      r++;
    } else {
      std::string word;
      for (int i = r - 1; i >= l; i--) {
        word += s[i];
      }
      words.emplace_back(word);

      while (r < n && s[r] == ' ') {
        r++;
      }
      l = r;
    }
  }

  std::string word;
  for (int i = r - 1; i >= l; i--) {
    word += s[i];
  }
  words.emplace_back(word);

  for (int i = 0; i < words.size(); i++) {
    res += words[i];
    if (i != words.size() - 1) {
      res += ' ';
    }
  }

  return res;
}

// leetcode557 共同喜欢的餐厅，最小index和
std::vector<std::string> LeetString::findRestaurant(
    std::vector<std::string> &list1, std::vector<std::string> &list2) {
  // 答案
  std::vector<std::string> res;
  std::unordered_map<std::string, int> index;

  for (int i = 0; i < list1.size(); i++) {
    index[list1[i]] = i;
  }

  int min = INT_MAX;
  for (int i = 0; i < list2.size(); i++) {
    if (index.count(list2[i]) > 0) {
      int j = index[list2[i]];
      if (j + i < min) {
        min = i + j;
        res.clear();
        res.emplace_back(list2[i]);
      } else if (j + i == min) {
        res.emplace_back(list2[i]);
      }
    }
  }

  return res;
}

// leetcode657 回到原点
bool LeetString::judgeCircle(std::string moves) {
  // 自己完成
  int len = moves.size();
  int x = 0;
  int y = 0;
  for (int i = 0; i < len; i++) {
    char cur = moves[i];
    if ('L' == cur) {
      x++;
    } else if ('R' == cur) {
      x--;
    } else if ('D' == cur) {
      y++;
    } else if ('U' == cur) {
      y--;
    }
  }

  return !x && !y;

  /*
  std::unordered_map<char, int> cnt;
  std::for_each(moves.begin(), moves.end(), [&cnt](char c) { cnt[c]++; });
  return cnt['U'] == cnt['D'] && cnt['L'] == cnt['R'];
  */
}

bool validPart(std::string s, int l, int r) {
  while (l <= r) {
    if (s[l] == s[r]) {
      ++l;
      --r;
    } else
      return false;
  }
  return true;
}

// leetcode680 验证回文（最多可以删除一个字符,顺序不改）
bool LeetString::validPalindrome(std::string s) {
  // 双指针
  // 答案
  if (s.size() <= 2) return true;
  int l = 0;
  int r = s.size() - 1;
  // bool remove_one = false;
  while (l <= r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else {
      return validPart(s, l + 1, r) || validPart(s, l, r - 1);
      /*
      // 局部最优解，个别情况会导致错误
      if (remove_one) {
        std::cout << "r0: " << r << std::endl;
        std::cout << "l0: " << l << std::endl;
        std::cout << "remove0: " << remove_one << std::endl;
        return false;
      }

      std::cout << "r1: " << r << ", " << s[r] << std::endl;
      std::cout << "l1: " << l << ", " << s[l] << std::endl;
      remove_one = true;
      if (s[l + 1] == s[r]) {
        l++;
      } else if (s[l] == s[r - 1]) {
        r--;
      } else {
        return false;
      }
      */
    }
  }

  // std::cout << "r: " << r << std::endl;
  // std::cout << "l: " << l << std::endl;
  // std::cout << "remove: " << remove_one << std::endl;

  return true;
}

int LeetString::countBinarySubstrings(std::string s) {
  // 未解决
  int res = 0;
  int len = s.size();
  for (int i = 0; i < len - 1; i++) {
    int count0 = 0;
    int count1 = 0;
    for (int j = i + 1; j < len; j++) {
      count0 = 0;
      count1 = 0;
      for (int k = i; k <= j; k++) {
        /*
        if ('0' == s[i]) {
          count0++;
        } else if ('1' == s[i]) {
          count1++;
        }
        */

        // 0或者1必须是连续的
        if (k == i) {
          if ('0' == s[k]) {
            count0++;
          } else if ('1' == s[k]) {
            count1++;
          }
        } else if (k > i) {
          if ('0' == s[k] && s[k - 1] == s[k]) {
            count0++;
          } else if ('1' == s[k] && s[k - 1] == s[k]) {
            count1++;
          }
        }
      }
      std::cout << "i: " << i << "j: " << j << ", count0: " << count0
                << ", count1: " << count1 << std::endl;
      if (count1 == count0) {
        res++;
      }
    }
  }

  return res;
}

// leetcode709 转换成小写字母
std::string LeetString::toLowerCase(std::string s) {
  std::string res;
  int len = s.size();
  for (int i = 0; i < len; i++) {
    char cur = s[i];
    if (cur >= 'A' && cur <= 'Z') {
      char low = cur + 'a' - 'A';
      res += low;
    } else {
      res += cur;
    }
  }

  return res;
}

// leetcode748 最短补全词
std::string shortestCompletingWord(std::string licensePlate,
                                   std::vector<std::string> &words) {
  // error
  std::string res;
  int len_min = INT_MAX;
  int len = (int)words.size();
  for (int i = 0; i < len; i++) {
    std::string word = words[i];
    bool find = true;
    for (int j = 0; j < licensePlate.size(); j++) {
      char cur = licensePlate[j];
      if ((cur >= 'a' && cur <= 'z')) {
        if (word.find(cur) == -1) {
          find = false;
        }
      } else if ((cur >= 'A' && cur <= 'Z')) {
        char low = cur + 'a' - 'A';
        if (word.find(low) == -1) {
          find = false;
        }
      }
    }
    if (find == true) {
      if (word.size() < len_min) {
        res = word;
        len_min = (int)word.size();
      }
    }
  }

  return res;
}

// leetcode748 最短补全词
std::string LeetString::shortestCompletingWord(
    std::string licensePlate, std::vector<std::string> &words) {
  // answer
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for (char &ch : licensePlate) {
    if (isalpha(ch)) cnt[tolower(ch) - 'a']++;
  }
  const int len = words.size();
  int idx = -1;  // words数组中第一个匹配到(gap最小)的最短单词在原数组中的index
  for (int i = 0; i < len; i++) {
    int c[26];
    memset(c, 0, sizeof(cnt));
    for (char &ch : words[i]) {
      c[ch - 'a']++;
    }
    bool isValid = true;
    for (int j = 0; j < 26; j++) {
      if (c[j] < cnt[j]) {
        isValid = false;
        break;
      }
    }
    if (isValid && (idx < 0 || words[i].size() < words[idx].size())) {
      idx = i;
    }
  }
  return words[idx];
}

// leetcode771 宝石数量
int LeetString::numJewelsInStones(std::string jewels, std::string stones) {
  // resolve 20231102
  int res = 0;
  int count1[26];
  int count2[26];
  memset(count1, 0, sizeof(count1));
  memset(count2, 0, sizeof(count2));
  for (char &ch : jewels) {
    if (ch >= 'a' && ch <= 'z')
      count1[ch - 'a']++;
    else if (ch >= 'A' && ch <= 'Z')
      count2[ch - 'A']++;
  }

  for (char &ch : stones) {
    if (ch >= 'a' && ch <= 'z') {
      res += count1[ch - 'a'];
    } else if (ch >= 'A' && ch <= 'Z') {
      res += count2[ch - 'A'];
    }
  }

  return res;
}

// leetcode796 旋转字符串
bool LeetString::rotateString(std::string s, std::string goal) {
  // resolve 20231102
  // resolve1
  /*
  if (s.size() != goal.size()) return false;
  if (s == goal) return true;
  int len = (int)s.size();
  for (int i = 1; i < len; i++) {
    std::string part1;
    std::string part2;
    for (int j = 0; j < i; j++) {
      part1 += s[j];
    }
    for (int k = i; k < len; k++) {
      part2 += s[k];
    }
    if (part2 + part1 == goal) return true;
  }
  return false;
  */

  // resolve2
  if (s.size() != goal.size()) return false;
  if (s == goal) return true;
  std::string doublegoal = goal + goal;
  return (-1 != doublegoal.find(s));
}

// leetcode804 唯一摩斯密码
int LeetString::uniqueMorseRepresentations(std::vector<std::string> &words) {
  // resolve 20231102
  // 简单题
  // 哈希表，每一个单词转换成摩斯码串，然后用哈希表记录出现次数
  int res = 0;
  std::vector<std::string> morse_label = {
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

  std::unordered_map<std::string, int> count;
  int len = words.size();
  for (std::string &word : words) {
    std::string morse;
    for (char &ch : word) {
      morse += morse_label[ch - 'a'];
    }
    if (!count[morse]) {
      count[morse]++;
      res++;
    } else {
      continue;
    }
  }

  return res;
}

std::vector<int> LeetString::numberOfLines(std::vector<int> &widths,
                                           std::string s) {
  // resolve 20231102
  std::vector<int> res;
  int row = 0;
  int col = 0;
  for (char &ch : s) {
    int cur_width = widths[ch - 'a'];
    if (col + cur_width > 100) {
      row++;
      col = 0;
    }
    col += cur_width;
  }

  res.emplace_back(++row);
  res.emplace_back(col);

  /*
  // error 不能截断，要补齐
  if (len % 100) {
    res.emplace_back(len / 100 + 1);
    res.emplace_back(len % 100);
  } else {
    res.emplace_back(len / 100);
    res.emplace_back(0);
  }
  */

  return res;
}

// leetcode819 出现次数最多单词
std::string LeetString::mostCommonWord(std::string paragraph,
                                       std::vector<std::string> &banned) {
  // ban
  // 双指针和哈希表,垃圾题目,放弃
  std::string res;
  std::string newstr;
  for (char &ch : paragraph) {
    if (ch >= 'A' && ch <= 'Z') {
      newstr += ch + 'a' - 'A';
    } else {
      newstr += ch;
    }
  }

  int len = (int)newstr.size();
  std::vector<std::string> words;
  std::string word;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i; j < len;) {
      char cur = newstr[j];
      if (cur >= 'a' && cur <= 'z') {
        j++;
      } else {
      }
    }
  }

  return res;
}

// leetcode821 最短距离
std::vector<int> LeetString::shortestToChar(std::string s, char c) {
  // resolve 20231102
  std::vector<int> idxs;
  int len = (int)s.size();
  for (int i = 0; i < len; i++) {
    char ch = s[i];
    if (c == ch) {
      idxs.emplace_back(i);
    }
  }

  std::vector<int> res;
  for (int i = 0; i < len; i++) {
    int min = INT_MAX;
    for (int &idx : idxs) {
      if (std::abs(i - idx) < min) {
        min = std::abs(i - idx);
      }
    }
    res.emplace_back(min);
  }

  return res;
}

std::string toGoatLatin(std::string sentence) {
  std::string res;

  return res;
}

std::string LeetString::toGoatLatin(std::string sentence) {
  // resolve 20231102
  std::string s = sentence;
  int n = (int)s.size();

  int l = 0;
  while (l < n && s[l] == ' ') {
    l++;
  }

  std::vector<std::string> words;
  int r = l;
  while (r < n) {
    if (s[r] != ' ') {
      r++;
    } else {
      std::string word;
      for (int i = l; i <= r - 1; i++) {
        word += s[i];
      }
      words.emplace_back(word);

      while (r < n && s[r] == ' ') {
        r++;
      }
      l = r;
    }
  }

  std::string word;
  for (int k = l; k < r; k++) {
    word += s[k];
  }
  words.emplace_back(word);

  std::vector<std::string> newwords;
  for (int i = 0; i < words.size(); i++) {
    std::string word = words[i];
    std::cout << "word: " << word << std::endl;
    char h = word[0];
    if ('a' == h || 'e' == h || 'i' == h || 'o' == h || 'u' == h || 'A' == h ||
        'E' == h || 'I' == h || 'O' == h || 'U' == h) {
      word += "ma";
      for (int k = 0; k <= i; k++) {
        word += 'a';
      }
      newwords.emplace_back(word);
    } else {
      std::string newword = "";
      for (int j = 1; j < word.size(); j++) {
        newword += word[j];
      }
      newword += word[0];
      newword += "ma";
      for (int k = 0; k <= i; k++) {
        newword += 'a';
      }
      newwords.emplace_back(newword);
    }
  }

  std::string res;
  for (int i = 0; i < newwords.size(); i++) {
    std::string word = newwords[i];
    res += word;
    if (i < newwords.size() - 1) {
      res += ' ';
    }
  }

  return res;
}

// leetcode830 较大分组的位置
std::vector<std::vector<int>> LeetString::largeGroupPositions(std::string s) {
  // resolve 20231107
  // 一次遍历
  std::vector<std::vector<int>> res;
  if (s.size() < 3) return res;
  int i = 0;
  int j = 1;
  int len = (int)s.size();
  while (i < len - 1 && j < len - 1) {
    std::vector<int> cur(2);
    while (s[i] == s[j]) {
      j++;
    }
    cur[0] = i;
    cur[1] = j - 1;
    if (j - i >= 3) {
      res.emplace_back(cur);
    }
    i = j;
    j++;
  }
  return res;
}

// leetcode844 比较含退格的字符串
bool LeetString::backspaceCompare(std::string s, std::string t) {
#if 0
  // resolve 20231107
  // 栈+一次遍历
  std::vector<char> stack1;
  std::vector<char> stack2;
  for (char ch : s) {
    if ('#' == ch) {
      if (!stack1.empty()) {
        stack1.pop_back();
      }
    } else {
      stack1.emplace_back(ch);
    }
  }

  for (char ch : t) {
    if ('#' == ch) {
      if (!stack2.empty()) {
        stack2.pop_back();
      }
    } else {
      stack2.emplace_back(ch);
    }
  }

  if (stack1.size() != stack2.size()) return false;

  for (int i = 0; i < stack1.size(); i++) {
    if (stack1[i] != stack2[i]) return false;
  }

  return true;
#else
  // resolve 20231107
  // 从后向前一次遍历，不引入辅助空间，即空间复杂度O(1)
  int i = s.size() - 1;
  int j = t.size() - 1;

  int back_count1 = 0;
  int back_count2 = 0;
  while (i >= 0 || j >= 0) {
    while (i >= 0) {
      if ('#' == s[i]) {
        ++back_count1;
        --i;
      } else if (back_count1 > 0) {
        --back_count1;
        --i;
      } else if (0 == back_count1) {
        break;
      }
    }

    while (j >= 0) {
      if ('#' == t[j]) {
        ++back_count2;
        --j;
      } else if (back_count2 > 0) {
        --back_count2;
        --j;
      } else if (0 == back_count2) {
        break;
      }
    }

    if (i >= 0 && j >= 0) {
      if (s[i] != t[j]) return false;
    } else if (i >= 0 || j >= 0) {
      return false;
    }
    --i;
    --j;
  }

  return true;
#endif
}

bool isLetter(char a) {
  if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z') return true;
  return false;
}

std::string reverseOnlyLetters(std::string s) {
  // resolve 20231107
  // 双指针
  int i = 0;
  int j = s.size() - 1;

  while (i < j) {
    while (!isalpha(s[i])) {
      i++;
      if (i >= j) {
        return s;
      }
    }
    while (!isalpha(s[j])) {
      j--;
      if (i >= j) {
        return s;
      }
    }
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;

    if (i >= j) {
      return s;
    }
    i++;
    j--;
  }

  return s;
}

// leetcode925 长按键入
bool LeetString::isLongPressedName(std::string name, std::string typed) {
  // ans 20231107
  // 双指针分别一次遍历
  int i = 0;
  int j = 0;

  while (j < typed.size()) {
    if (name[i] == typed[j] && i < name.size()) {
      j++;
      i++;
    } else if (j > 0 && typed[j] == typed[j - 1]) {
      j++;
    } else {
      return false;
    }
  }

  return i == name.size();
}

// leetcode942 增减字符串匹配
std::vector<int> LeetString::diStringMatch(std::string s) {
  // ans 20231107
  // 贪心 升序I添加最小值，降序D添加最大值
  std::vector<int> res;
  int i = 0;
  int j = (int)s.size();
  for (char ch : s) {
    if ('I' == ch) {
      res.emplace_back(i++);
    } else if ('D' == ch) {
      res.emplace_back(j--);
    }
  }

  res.emplace_back(i);

  return res;
}

// leetcode944 删列造序
int LeetString::minDeletionSize(std::vector<std::string> &strs) {
  int res = 0;
  int n = strs.size();
  int len = strs[0].size();

  for (int i = 0; i < len; i++) {
    bool match = true;
    for (int j = 1; j < n; j++) {
      if (strs[j][i] - strs[j - 1][i] < 0) {
        match = false;
        break;
      }
    }
    if (match) res++;
  }

  return len - res;
}

bool gcdOfStringsCheck(std::string str1, std::string str2, std::string src) {
  int len = src.size();
  if (0 == str1.size() % len && 0 == str2.size() % len) {
    std::string tmp1;
    for (int j = 0; j < str1.size() / len; j++) {
      tmp1 += src;
    }
    std::string tmp2;
    for (int k = 0; k < str2.size() / len; k++) {
      tmp2 += src;
    }
    if (str1 == tmp1 && str2 == tmp2) {
      return true;
    }
  }

  return false;
}

// leetcode1071 字符串的最大公因子
std::string LeetString::gcdOfStrings(std::string str1, std::string str2) {
#if 0
  // resolve 20231107
  // 枚举，注意是从最长的开始枚举，一旦符合就返回，而不是从最短开始
  std::string src;
  if (str1.size() > str2.size())
    src = str2;
  else
    src = str1;

  if (gcdOfStringsCheck(str1, str2, src)) {
    return src;
  }

  char head = src[0];
  for (int i = src.size(); i >= 1; i--) {
    std::string tmp;
    if (head == src[i]) {
      tmp = src.substr(0, i);
      if (gcdOfStringsCheck(str1, str2, tmp)) {
        return tmp;
      }
    }
  }

  return "";
#else
  // resolve 20231107
  // 优化的枚举，注意str1+str2等于str2+str1，是两者有最大【公约字符串】的充要条件
  // 然后开始枚举，注意是从最长的开始枚举，一旦符合就返回，而不是从最短开始
  if (str1 + str2 != str2 + str1) return "";
  std::string src;
  if (str1.size() > str2.size())
    src = str2;
  else
    src = str1;

  if (gcdOfStringsCheck(str1, str2, src)) {
    return src;
  }

  char head = src[0];
  for (int i = src.size(); i >= 1; i--) {
    std::string tmp;
    if (head == src[i]) {
      tmp = src.substr(0, i);
      if (gcdOfStringsCheck(str1, str2, tmp)) {
        return tmp;
      }
    }
  }

  return "";

#endif
}

// leetcode1078 Bigram分词
std::vector<std::string> LeetString::findOcurrences(std::string text,
                                                    std::string first,
                                                    std::string second) {
  // resolve 20231107
  // 遍历
  std::vector<std::string> words;
  int s = 0, e = 0, len = (int)text.size();
  while (true) {
    while (s < len && text[s] == ' ') {
      s++;
    }
    if (s >= len) {
      break;
    }
    e = s + 1;
    while (e < len && text[e] != ' ') {
      e++;
    }
    words.emplace_back(text.substr(s, e - s));
    s = e + 1;
  }

  std::vector<std::string> res;
  if (words.size() < 3) return res;

  for (int i = 2; i < words.size(); i++) {
    if (first == words[i - 2] && second == words[i - 1]) {
      res.emplace_back(words[i]);
    }
  }

  return res;
}

// leetcode1108 IP 地址无效化
std::string LeetString::defangIPaddr(std::string address) {
  std::string res = "";
  for (char ch : address) {
    ('.' == ch) ? res += "[.]" : res += ch;
  }

  return res;
}

// leetcode1154 一年中的第几天
int LeetString::dayOfYear(std::string date) {
  // ans 20231107
  // "2019-01-09"
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(5, 2));
  int day = stoi(date.substr(8, 2));

  int amount[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    ++amount[1];
  }

  int ans = 0;
  for (int i = 0; i < month - 1; ++i) {
    ans += amount[i];
  }
  return ans + day;
}

// leetcode5 最长回文
std::string LeetString::longestPalindrome5(std::string s) {
  // resolve 20231108
  // DP+枚举
  // DP从短开始往长规划
  int n = s.size();
  if (n < 2) {
    return s;
  }

  // dp[i][j] 表示 s[i..j] 是否是回文串
  std::vector<std::vector<int>> dp(n, std::vector<int>(n));
  // 初始化：所有长度为 1 的子串都是回文串
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  int len_max = 1;
  int begin = 0;

  // 先枚举子串长度
  for (int len = 2; len <= n; len++) {
    // 枚举左边界
    for (int i = 0; i < n; i++) {
      // 确定右边界，即 j - i + 1 = len
      int j = len + i - 1;
      // 如果右边界越界，就可以退出当前循环
      if (j >= n) {
        break;
      }

      if (s[i] != s[j]) {
        dp[i][j] = false;
      } else {
        if (j - i < 3) {
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
      }

      if (dp[i][j] && j - i + 1 > len_max) {
        len_max = j - i + 1;
        begin = i;
      }
    }
  }

  return s.substr(begin, len_max);
}

// leetcode6 N字形变换
std::string LeetString::convert(std::string s, int numRows) {
  // resolve 20231108
  // 遍历
  if (numRows < 2) return s;
  std::vector<std::string> rows(numRows);
  int i = 0, flag = -1;
  // 引入flag按照Z型填充矩阵
  for (char c : s) {
    rows[i].push_back(c);
    if (i == 0 || i == numRows - 1) flag = -flag;
    i += flag;
  }

  std::string res;
  for (const std::string &row : rows) res += row;
  return res;
}

// leetcode8 字符串转换整数(atoi)
int LeetString::myAtoi(std::string str) {
  // resolve 20191109
  if (!str.size()) return 0;

  int sign = 1, base = 0, i = 0, n = str.size();
  while (i < n && str[i] == ' ') ++i;  //注意跳过空格
  if (str[i] == '+' || str[i] == '-') {
    sign = (str[i++] == '+') ? 1 : -1;
  }
  while (i < n && str[i] >= '0' && str[i] <= '9') {
    // 注意超出int范围
    if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }
    base = 10 * base + (str[i] - '0');
    i++;
  }

  return base * sign;
}

// leetcode38 外观数列
std::string countAndSay(int n) {
  // resolve 20231108
  // 遍历+枚举
  if (1 == n) return "1";

  std::string res = "1";
  for (int i = 2; i < n; i++) {
    std::string cur = "";
    int s = 0;
    int e = 0;
    while (e < res.size()) {
      while (e < res.size() && res[s] == res[e]) {
        ++e;
      }
      cur += std::to_string(e - s);
      cur += res[s];
      s = e;
    }
    res = cur;
  }

  return res;
}

}  // namespace myleet