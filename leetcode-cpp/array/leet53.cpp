#include <cmath>
#include <iostream>
#include <algorithm>
#include "switch.h"

using namespace std;

class Solution {
public:
	//动态规划
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

	//分治法
	int maxSubArray2(int* array, int len)
	{
		return helper(array, 0, len-1);
	}

	int helper(int* a, int left, int right)
	{
		if (left >= right)
			return a[left];

		int mid = left + (right - left) / 2;
		int maxl = helper(a, left, mid - 1);
		int maxr = helper(a, mid+1, right);
		int mmax = a[mid], t = mmax;
		for (int i = mid-1; i >= left; i--) {
			t += a[i];
			mmax = max(mmax, t);
		}
		t = mmax;
		for (int i = mid + 1; i <= right; i++) {
			t += a[i];
			mmax = max(mmax, t);
		}
		return max(mmax, max(maxl, maxr));
	}

};

#ifdef S53
int main()
{
	Solution S;
	int array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int len = sizeof(array) / sizeof(int);
	cout << "max = " << S.maxSubArray2(array, len);
}
#endif

