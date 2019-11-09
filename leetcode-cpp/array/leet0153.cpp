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

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
************************************************************************************/

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		if (nums[left] > nums[right]) {
			while (left != right - 1) {
				mid = left + (right - left) / 2;
				if (nums[left] < nums[mid]) left = mid;
				else if (nums[right] > nums[mid]) right = mid;
			}
		}

		return min(nums[left], nums[right]);
	}
};

#ifdef LT0153 
int main()
{
	Solution S;

	vector<int> array = { 2, 7, 8, 9 , 1};

	int minValue = S.findMin(array);
	std::cout << "the min of array is: " << minValue << std::endl;

	return 0;
}
#endif
