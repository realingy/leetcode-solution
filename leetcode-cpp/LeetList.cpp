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

// leetcode141 <==> leetcode142 <==> leetcode876 <==> leetcode143
// leetcode141 环形链表
bool LeetList::hasCycle(ListNode* head) {
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
  ListNode* slow = head;
  ListNode* fast = head->next;
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

// leetcode141 <==> leetcode142 <==> leetcode876 <==> leetcode143
// leetcode876 链表的中间节点
ListNode* LeetList::middleNode(ListNode* head) {
  // ans 20231112
  // 双指针（快慢指针）
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// leetcode141 <==> leetcode142 <==> leetcode876 <==> leetcode143
// leetcode142 环形链表II
ListNode* LeetList::detectCycle(ListNode* head) {
#if 0
  // resolve 20231112
  // 哈希set
  std::unordered_set<ListNode*> hash;
  auto p = head;
  while (p) {
    if (hash.count(p)) return p;
    hash.insert(p);
    p = p->next;
  }
  return nullptr;
#else
  // resolve 20231112
  // 快慢指针，相遇以后，slow和head开始一起走，最终会在入口处相遇
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      while (slow != head) {
        slow = slow->next;
        head = head->next;
      }
      return slow;
    }
  }
  return nullptr;
#endif
}

// leetcode143 重排链表
void LeetList::reorderList(ListNode* head) {
  // ans 20231112
  // 找到中间节点，然后将中间节点后半部分倒置，然后循环插入前后节点
  // 1.找到中间节点（重点：如果有两个中间节点，这里算出来的是后一个！！！！！）
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  auto mid = slow;  // 记录中间节点

  // 2.反转后半部分，然后让mid只想空用于后续循环
  ListNode* pre;
  ListNode* cur = mid;
  while (cur) {
    ListNode* next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  mid->next = nullptr;

  // 3.左右插入
  ListNode* left = head;
  ListNode* right = pre;  // 末尾节点
  while (right->next) {
    auto next1 = left->next;
    auto next2 = right->next;
    left->next = right;
    right->next = next1;
    left = next1;
    right = next2;
  }
}

// leetcode160 相交链表
ListNode* LeetList::getIntersectionNode(ListNode* headA, ListNode* headB) {
  // resolve 20231104
  // 哈希set
  std::unordered_set<ListNode*> process1;
  ListNode* temp = headA;
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

}  // namespace myleet