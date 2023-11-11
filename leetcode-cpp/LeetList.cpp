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

// leetcode206 反转链表
ListNode* LeetList::reverseList(ListNode* head) {
  if (head == nullptr || nullptr == head.next) return head;
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

}  // namespace myleet