#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }

	vector<int> twoSum2(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.count(target - nums[i])) {
				return { i, m[target - nums[i]] };
			}
			m[nums[i]] = i;
		}
		return {};
	}

};

#if 0
int main()
{
	Solution S;

	vector<int> array = { 2, 7, 8, 9 };
	vector<int> res1 = S.twoSum(array, 9);
	vector<int> res2 = S.twoSum2(array, 9);

	for (int i = 0; i < res1.size(); i++) {
		cout << res1[i] << " ";
	}

	cout << '\n';

	for (auto i : res2)
		cout << i << ' ';
}
#endif
