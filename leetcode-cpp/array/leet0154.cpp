#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include "switch.h"

using namespace std;

/************************************************************************************
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

假设数组中存在重复元素。

示例1:
输入: [1,3,5]
输出: 1

示例2:
输入: [2,2,2,0,1]
输出: 0
************************************************************************************/

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int res = nums[0];
		while (left < right - 1) {
			int mid = left + (right - left) / 2;
			if (nums[left] < nums[mid]) {
				res = min(res, nums[left]);
				left = mid + 1;
			} else if (nums[right] > nums[mid]) {
				res = min(res, nums[right]);
				right = mid;
			} else {
				++left;
			}
		}

		return min(res, min(nums[left], nums[right]));
	}
};

#ifdef LT0154 
int main()
{
	Solution S;

	vector<int> array = { 2, 2, 2, 0, 1};

	int minValue = S.findMin(array);
	std::cout << "the min of array is: " << minValue << std::endl;

	return 0;
}
#endif
