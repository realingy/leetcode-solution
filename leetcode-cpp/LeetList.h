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
  static ListNode* rotateRight(ListNode* head, int k);
  // leetcode206 反转链表
  static ListNode* reverseList(ListNode* head);
  // leetcode92 反转链表II
  static ListNode* reverseBetween(ListNode* head, int left, int right);
  // leetcode25 K 个一组翻转链表
  static ListNode* reverseKGroup(ListNode* head, int k);
  // leetcode141 环形链表
  static bool hasCycle(ListNode* head);
  // leetcode876 链表的中间节点
  static ListNode* middleNode(ListNode* head);
  // leetcode142 环形链表II
  static ListNode* detectCycle(ListNode* head);
  // leetcode160 相交链表
  static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
  // leetcode143 重排链表
  static void reorderList(ListNode* head);
  // leetcode1143 最长公共子序列
  static ListNode* removeElements(ListNode* head, int val);
  // leetcode234 回文链表
  static bool isPalindrome(ListNode* head);
  // leetcode239 滑动窗口最大值
  static std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
  // leetcode83 删除排序链表中的重复元素
  static ListNode* deleteDuplicates(ListNode* head);
  // leetcode82 删除排序链表中的重复元素II
  static ListNode* deleteDuplicates2(ListNode* head);
};

}  // namespace myleet

#endif