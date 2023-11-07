#include "LeetHash.h"

#include <algorithm>
#include <iostream>

namespace myleet {

//
int LeetHash::romanToInt(std::string s) {
  // resolve 20231104
  // 定义一个哈希表存储罗马数字
  std::unordered_map<char, int> map;
  map.insert({{'I', 1},
              {'V', 5},
              {'X', 10},
              {'L', 50},
              {'C', 100},
              {'D', 500},
              {'M', 1000}});

  // 如果当前字符代表的数字小于后面的字符代表的数字，则需要做减法操作；
  // 否则，直接累加当前字符代表的整数值。
  int ans = 0;
  int temp = 0;  //将当前的数字转换成下一轮循环的后面的数字
  int len = s.size();
  // 从后往前遍历字符串
  for (int i = len - 1; i >= 0; i--) {
    int cur = map[s[i]];  // 当前的数字
    // 如果当前的数字小于后面的数字,执行减法操作
    if (cur < temp) {
      ans -= cur;
    } else {
      ans += cur;
    }
    temp = cur;  //下一轮循环中后面的数字
  }
  return ans;
}

// leetcode141 环形链表
bool LeetHash::hasCycle(ListNode *head) {
#if 0
  // resolve 20231104
  // 哈希set
  std::unordered_set<ListNode *> processed;
  while (head != nullptr) {
    if (processed.count(head)) return true;
    processed.insert(head);
    head = head->next;
  }

  return false;
#else
  // resolve 20231104
  // 双指针
  if (head == nullptr || head->next == nullptr) {
    return false;
  }
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) {
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
#endif
}

// leetcode160 相交链表
ListNode *LeetHash::getIntersectionNode(ListNode *headA, ListNode *headB) {
  // resolve 20231104
  // 哈希set
  std::unordered_set<ListNode *> process1;
  ListNode *temp = headA;
  while (nullptr == temp) {
    process1.insert(temp);
    temp = temp->next;
  }
  temp = headB;
  while (nullptr == temp) {
    if (process1.count(temp)) return temp;
    temp = temp->next;
  }

  return nullptr;
}

// leetcode169 多数元素
int LeetHash::majorityElement(std::vector<int> &nums) {
  // resolve 20231104
  // 哈希表
  std::unordered_map<int, int> count;
  int max = INT_MIN;
  int x;
  for (int n : nums) {
    ++count[n];
    if (count[n] > max) {
      x = n;
      max = count[n];
    }
  }

  return x;
}

// leetcode383 赎金信
bool LeetHash::canConstruct(std::string ransomNote, std::string magazine) {
  // resolve 20231105
  // 哈希表
  std::unordered_map<char, int> count;
  for (char ch : magazine) {
    ++count[ch];
  }

  for (char ch : ransomNote) {
    if (!count[ch]) return false;
    --count[ch];
  }

  return true;
}

// leetcode387 字符串中的第一个唯一字符
int LeetHash::firstUniqChar(std::string s) {
  std::unordered_map<char, int> map;
  for (int i = 0; i < s.size(); i++) {
    char cur = s[i];
    map[cur]++;
  }
  for (int i = 0; i < s.size(); i++) {
    char cur = s[i];
    if (map[cur] == 1) return i;
  }
  return -1;
}

// leetcode448 找到所有数组中消失的数字
std::vector<int> LeetHash::findDisappearedNumbers(std::vector<int> &nums) {
#if 0
  // resolve 20231105
  // 哈希表
  std::vector<int> res;
  std::unordered_map<int, int> count;
  for (int n : nums) {
    ++count[n];
  }

  int n = (int)nums.size();
  for (int i = 1; i <= n; i++) {
    if (!count[i]) res.emplace_back(i);
  }

  return res;
#else
  // ans 20231105
  // 数组方法
  // 1 将数组元素对应为索引的位置加n
  // 2 遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在

  std::vector<int> res;

  int n = nums.size();
  for (int i = 0; i < n; i++) {
    nums[(nums[i] - 1) % n] += n;
  }

  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < n; i++) {
    if (nums[i] <= n) {
      res.push_back(i + 1);
    }
  }

  return res;
#endif
}

// leetcode496 下一个更大元素I
std::vector<int> LeetHash::nextGreaterElement(std::vector<int> &nums1,
                                              std::vector<int> &nums2) {
  // ans 20231105
  // 栈+哈希表
  // 倒序遍历nums2，得到每一个数字的下一个更大值（使用栈做辅助）,并使用哈希表存储(在数组没有重复数字的前提下)
  // O(nums1.size() + nums2.size())
  std::vector<int> res;
  std::unordered_map<int, int> map;
  std::vector<int> stack;
  int n = (int)nums2.size();
  for (int i = n - 1; i >= 0; i--) {
    int cur = nums2[i];
    if (!stack.empty()) {
      while (stack.back() < cur && !stack.empty()) {
        stack.pop_back();
      }
    }

    if (stack.empty()) {
      map[cur] = -1;
    } else {
      map[cur] = stack.back();
    }

    stack.emplace_back(cur);
  }

  for (int n : nums1) {
    res.emplace_back(map[n]);
  }

  return res;
}

// leetcode575 分糖果
int LeetHash::distributeCandies(std::vector<int> &candyType) {
  // ans 20231105
  // 哈希表
  // 糖果种类小于n/2,可以选完所有种类
  // 糖果种类大于n/2,可以选n/2不同种类
  int n = (int)candyType.size();
  std::unordered_map<int, int> count;
  int type_count = 0;
  for (int type : candyType) {
    if (!count[type]) type_count++;
    count[type]++;
  }

  return std::min(type_count, n / 2);
}

// leetcode645 错误的集合
std::vector<int> LeetHash::findErrorNums(std::vector<int> &nums) {
  // resolve 20231103
  // 哈希
  std::vector<int> errorNums(2);
  int n = nums.size();
  std::unordered_map<int, int> mp;
  for (auto &num : nums) {
    mp[num]++;
  }
  for (int i = 1; i <= n; i++) {
    int count = mp[i];
    if (count == 2) {
      errorNums[0] = i;
    } else if (count == 0) {
      errorNums[1] = i;
    }
  }
  return errorNums;
}

// leetcode697 数组的度
int LeetHash::findShortestSubArray(std::vector<int> &nums) {
  // ans 20231105
  // 双哈希表
  // 动态记录数组的度，同时使用辅助哈希表记录当前数第一次出现的位置
  int res = INT_MAX;
  std::unordered_map<int, int> count;
  std::unordered_map<int, int> first;

  int n = 0;
  int len = (int)nums.size();
  for (int i = 0; i < len; i++) {
    int num = nums[i];
    count[num]++;
    if (1 == count[num]) {
      first[num] = i;
    }

    if (count[num] == n) {
      if (i - first[num] + 1 < res) {
        res = i - first[num] + 1;
      }
    } else if (count[num] > n) {
      res = i - first[num] + 1;
      n = count[num];
    }
  }

  return res;
}

// leetcode819 最常见的单词
std::string LeetHash::mostCommonWord(std::string paragraph,
                                     std::vector<std::string> &banned) {
  // resolve 20231105
  // 哈希表，先整理好word表，然后记录每一个单词的出现次数
  std::unordered_map<std::string, int> hash;
  std::string s = paragraph;
  std::string word;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {  // end
      if (!word.empty()) {
        hash[word]++;
        word.clear();
      }
    } else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
      if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
      word += s[i];
    }
  }

  if (!word.empty()) {
    hash[word]++;
  }

  for (std::string word : banned) {
    hash.erase(word);
  }

  std::string res;
  for (std::pair<std::string, int> k : hash) {
    if (hash[res] < k.second) {
      res = k.first;
    }
  }

  return res;
}

// leetcode859 亲密字符串
bool LeetHash::buddyStrings(std::string s, std::string goal) {
  // ans 20231105
  // 分两种情况，第一种是两个字符串完全相等，但是有一个重复的字符，可以满足
  // 第二种就是两个字符串不相等，但是只有两个字符不相等，且位置是可以对调的
  // 最重要的是考虑到第一种情况
  int cnt = 0;
  if (s.size() != goal.size()) return false;

  int diff1 = -1;
  int diff2 = -1;
  int count[26];
  memset(count, 0, sizeof(count));
  bool repeat = false;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] != goal[i]) {
      cnt++;
      if (cnt > 2) return false;
      if (cnt == 1) diff1 = i;
      if (cnt == 2) diff2 = i;
    }
    count[s[i] - 'a']++;
    if (count[s[i] - 'a'] >= 2) repeat = true;
  }

  // 第一种情况，两个串一摸一样，需要有重复字母
  if (cnt == 0 && repeat) return true;
  // 第二种情况，两个串有两个位置不同，需要正好可以互换
  if (cnt == 2 && s[diff1] == goal[diff2] && s[diff2] == goal[diff1])
    return true;

  return false;
}

// leetcode884 两句话中的不常见单词
std::vector<std::string> LeetHash::uncommonFromSentences(std::string s1,
                                                         std::string s2) {
  // resolve 20231105
  // 简单题，最重要的是分割单词
  std::vector<std::string> res;
  std::unordered_map<std::string, int> count;
  std::string cur;
  for (char ch : s1) {
    if (' ' == ch) {
      if (!cur.empty()) {
        count[cur]++;
        cur.clear();
      }
    } else {
      cur += ch;
    }
  }

  if (!cur.empty()) {
    count[cur]++;
    cur.clear();
  }

  for (char ch : s2) {
    if (' ' == ch) {
      if (!cur.empty()) {
        count[cur]++;
        cur.clear();
      }
    } else {
      cur += ch;
    }
  }

  if (!cur.empty()) {
    count[cur]++;
    cur.clear();
  }

  // 遍历hash表，查看每一个单词出现频次
  for (std::pair<std::string, int> k : count) {
    if (1 == k.second) res.emplace_back(k.first);
  }

  return res;
}

// leetcode914 卡牌分组
bool LeetHash::hasGroupsSizeX(std::vector<int> &deck) {
  // resolve 20231105
  // 枚举各种可能的分法，注意只分一组的极限情况
  std::unordered_map<int, int> count;
  for (int n : deck) {
    ++count[n];
  }

  for (int i = 2; i <= deck.size(); i++) {
    // i等于deck.size()是只分一组的极限情况
    bool match = true;
    for (std::pair<int, int> c : count) {
      if (c.second % i) match = false;
    }
    if (true == match) return true;
  }

  return false;
}

// leetcode929 独特的邮件地址
int LeetHash::numUniqueEmails(std::vector<std::string> &emails) {
  // ans 20231105
  // hash set的用法
  std::unordered_set<std::string> emailSet;
  for (auto &email : emails) {
    std::string local;
    for (char c : email) {
      if (c == '+' || c == '@') {
        // "+"之后的地址名无效
        break;
      }
      if (c != '.') {
        // "."无效等于空
        local += c;
      }
    }
    emailSet.emplace(local + email.substr(email.find('@')));
  }
  return emailSet.size();
}

// leetcode953 验证外星语词典
bool LeetHash::isAlienSorted(std::vector<std::string> &words,
                             std::string order) {
  // ans 20231105
  // 遍历
  std::vector<int> index(26);
  for (int i = 0; i < order.size(); i++) {
    index[order[i] - 'a'] = i;
  }
  for (int i = 1; i < words.size(); i++) {
    bool valid = false;
    for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {
      int prev = index[words[i - 1][j] - 'a'];
      int curr = index[words[i][j] - 'a'];
      if (prev < curr) {
        valid = true;
        break;
      } else if (prev > curr) {
        return false;
      }
    }
    if (false == valid) {
      // if (words[i - 1].size() > words[i].size()) {
      return false;
      // }
    }
  }
  return true;
}

// leetcode961 在长度 2N 的数组中找出重复 N 次的元素
int LeetHash::repeatedNTimes(std::vector<int> &nums) {
  // resolve 20231105
  // 一旦重复就是答案
  std::unordered_map<int, int> count;
  for (int n : nums) {
    if (count[n] > 1) return n;
    ++count[n];
  }
}

std::vector<std::string> commonChars(std::vector<std::string> &words) {
  // resolve 20231107
  // 双哈希，时间有点慢
  std::vector<std::string> res;
  std::unordered_map<int, int> count_min;
  for (int i = 0; i <= 26; i++) {
    count_min[i] = INT_MAX;
  }

  for (std::string word : words) {
    std::unordered_map<int, int> count;
    for (char ch : word) {
      count[ch - 'a']++;
    }
    for (int i = 0; i <= 26; i++) {
      count_min[i] = std::min(count[i], count_min[i]);
    }
  }

  for (int i = 0; i <= 26; i++) {
    std::string str;
    while (count_min[i]) {
      str = (i + 'a');
      res.emplace_back(str);
      count_min[i]--;
    }
  }

  return res;
}

}  // namespace myleet