#ifndef __LEET_LIST_H__
#define __LEET_LIST_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "data.h"

namespace myleet {

class LeetList {
 public:
  LeetList() {}
  ~LeetList() {}

 public:
  // leetcode61 旋转链表
  ListNode* rotateRight(ListNode* head, int k);
  // leetcode206 反转链表
  ListNode* reverseList(ListNode* head);
  // leetcode92 反转链表II
  ListNode* reverseBetween(ListNode* head, int left, int right);
};

}  // namespace myleet

#endif