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
  // leetcode2487 从链表中移除节点
  static ListNode* removeNodes(ListNode* head);
  // leetcode445 两数相加II
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
  // leetcode2816 翻倍以链表形式表示的数字
  static ListNode* doubleIt(ListNode* head);
  // leetcode2 两数相加
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (nullptr != l1 || nullptr != l2) {
      int n1 = (nullptr != l1) ? l1->val : 0;
      int n2 = (nullptr != l2) ? l2->val : 0;
      int n = n1 + n2 + carry;
      if (nullptr == head) {
        head = tail = new ListNode(n % 10);
      } else {
        tail->next = new ListNode(n % 10);
        tail = tail->next;
      }
      carry = int(n / 10);
      if (nullptr != l1) {
        l1 = l1->next;
      }
      if (nullptr != l2) {
        l2 = l2->next;
      }
    }
    if (carry > 0) {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};

}  // namespace myleet

#endif