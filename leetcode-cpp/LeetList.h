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
  // leetcode25 K 个一组翻转链表
  ListNode* reverseKGroup(ListNode* head, int k);
  // leetcode141 环形链表
  static bool hasCycle(ListNode* head);
  // leetcode876 链表的中间节点
  ListNode* middleNode(ListNode* head);
  // leetcode142 环形链表II
  ListNode* detectCycle(ListNode* head);
  // leetcode160 相交链表
  static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
};

}  // namespace myleet

#endif