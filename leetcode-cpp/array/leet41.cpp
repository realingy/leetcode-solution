#include <iostream>
#include <vector>
#include "switch.h"

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//[0...i] is[1...i]
		int n = nums.size();
		if (!n) return 1;
		int i = 0;
		while (i < n) {
			//不在自己的位置上,就放到自己正确的位置上去
			if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			} else {
				++i;
			}
		}

		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};

#ifdef LT0041
int main()
{
	Solution S;

	vector<int> nums = {1, -1, 3, 4};
	cout << "first missing positive is: " << S.firstMissingPositive(nums) << endl;

	return 0;
}
#endif
