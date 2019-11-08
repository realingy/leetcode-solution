#include <iostream>
#include <algorithm>
#include "switch.h"

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m[256] = { 0 };
		int l = s.size();
		int res = 0, left = 0;
		for (int i = 0; i < l; i++)
		{
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = max(res, i - left + 1);
			}
			else {
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}
};

#ifdef S003
int main()
{
	Solution S;

	string str = "pwwkew";
	int len = S.lengthOfLongestSubstring(str);
	cout << "lenght of lengest substring: " << len << endl;

	return 0;
}
#endif
