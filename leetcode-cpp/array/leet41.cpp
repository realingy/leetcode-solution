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
			//�����Լ���λ����,�ͷŵ��Լ���ȷ��λ����ȥ
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
