//#include "leet01.cpp"
#include "leet02.cpp"

int main()
{
	Solution S;

#if 0
	//1. two sum
	vector<int> array = { 2, 7, 8, 9 };
	vector<int> res1 = S.twoSum(array, 9);
	vector<int> res2 = S.twoSum2(array, 9);

	for(int i = 0; i < res1.size();  i++) {
		cout << res1[i] << " ";
	}

	cout << '\n';

	for (auto i : res2)
		cout << i << ' ';
#endif

	//2. add two sum
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *list = S.addTwoNumbers(l1, l2);
	while (list) {
		cout << list->val << " ";
		list = list->next;
	}

	return 0;
}
