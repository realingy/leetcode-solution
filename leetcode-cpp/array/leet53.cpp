#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	//��̬�滮
	int maxSubArray(int* array, int len)
	{
		int res = INT_MIN;
		int sum = 0;
		for (size_t i = 0; i < len; i++)
		{
			int num = array[i];
			sum = max(num, sum + num);
			res = max(sum, res);
		}
		return res;
	}
	//���η�
};

#if 1
int main()
{
	Solution S;
	int array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int len = sizeof(array) / sizeof(int);
	cout << "max = " << S.maxSubArray(array, len);
}
#endif

