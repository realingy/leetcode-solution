#include <iostream>
#include "switch.h"

/*
把一个0 - 1串（只包含0和1的串）进行排序，你可以交换任意两个位置，问最少交换的次数？
分析：快排partition。 最左边的那些0和最右边的那些1都可以不管
*/

class Solution {
public:
	int countOfExchange(int a[], int len)
	{
		int res = 0;
		for (int i = 0, j = len - 1; i < j; ++i, --j) {
			for (; (i < j) && (a[i] == 0); ++i) ; 
			for (; (j > i) && (a[j] == 1); --j) ;
			if (i < j) ++res;
		}
		return res;
	}
};


#ifdef J001
int main()
{
	Solution S;
	int num[] = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1};
	int len = sizeof(num) / sizeof(int);
	int count = S.countOfExchange(num, len);
	std::cout << "count of exchange is: " << count << std::endl;

	return 0;
}

#endif
