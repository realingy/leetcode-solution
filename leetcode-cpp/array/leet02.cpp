#include <iostream>

struct ListNode
{
	ListNode(int v) {
		val = v;
	}
	int val;
	ListNode *next;
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return res->next;
    }
};

#if 0
int main()
{
	Solution S;

	//2. add two sum
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *list = S.addTwoNumbers(l1, l2);
	while (list) {
		std::cout << list->val << " ";
		list = list->next;
	}

	return 0;
}
#endif
