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

}  // namespace myleet