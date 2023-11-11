#include "LeetList.h"

#include <algorithm>
#include <iostream>

namespace myleet {

// leetcode61 旋转链表
ListNode* LeetList::rotateRight(ListNode* head, int k) {
  if (k == 0 || head == nullptr || head->next == nullptr) {
    return head;
  }
  int n = 1;
  ListNode* iter = head;
  while (iter->next != nullptr) {
    iter = iter->next;
    n++;
  }

  int add = n - k % n;
  if (add == n) {
    return head;
  }

  iter->next = head;  // 闭环
  while (add--) {
    iter = iter->next;
  }
  ListNode* ret = iter->next;
  iter->next = nullptr;
  return ret;
}

// 206 <=====> 92 <=====> 25
// leetcode206 反转链表
ListNode* LeetList::reverseList(ListNode* head) {
  if (head == nullptr || nullptr == head->next) return head;
  ListNode* pre;
  ListNode* cur = head;
  while (nullptr == cur) {
    ListNode* next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}

// 206 <=====> 92 <=====> 25
// leetcode92 反转链表 II
ListNode* LeetList::reverseBetween(ListNode* head, int left, int right) {
  // ans 20231111
  // 进阶版，注意引用哨兵节点dummy
  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* p = dummy;
  for (int i = 0; i < left - 1; i++) {
    p = p->next;
  }
  ListNode* pre;
  ListNode* cur = p->next;
  for (int i = 0; i < right - left + 1; i++) {
    ListNode* next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  p->next->next = cur;
  p->next = pre;

  return dummy->next;
}

// 206 <=====> 92 <=====> 25
// leetcode25 K个一组翻转链表
ListNode* LeetList::reverseKGroup(ListNode* head, int k) {
  // nas 20231111
  // leeocode92的进阶版，重点是每次都记录p的位置
  if (!head) return head;
  int n = 0;
  auto cur = head;
  while (cur) {
    n++;
    cur = cur->next;
  }

  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  auto p = dummy;

  while (n >= k) {
    n -= k;
    ListNode* pre;
    ListNode* cur = p->next;
    for (int i = 0; i < k; i++) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    auto next = p->next;
    p->next->next = cur;
    p->next = pre;
    p = next;
  }

  return dummy->next;
}

}  // namespace myleet