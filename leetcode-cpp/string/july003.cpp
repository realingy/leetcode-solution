#include <iostream>
#include "switch.h"

using namespace std;

/*
一个字符串只包含*和数字，请把它的*号都放开头

// 方法1 快排partition——数字相对顺序会变化
// 循环不变式：[0..i – 1]都是*, [i..j – 1]是数字，[j..n – 1]未探测
	
// 方法2 数字相对顺序不变：从后向前处理
*/

class Solution {
public:
	void resortPartition(string &s)
	{
		int n = s.size();
		for (int i = 0, j = 0; j < n; ++j) {
			if (s[j] == '*')
				swap(s[i++], s[j]);
		}
	}

	void resortReplace(string& s)
	{
		int n = s.size();
		int j = n - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (isdigit(s[i]))
				s[j--] = s[i];
		}
		for (; j >= 0; --j) 
			s[j] = '*';
	}

};


#ifdef J003
int main()
{
	Solution S;
	string str = "*01*2*4";
	// S.resortPartition(str);
	S.resortReplace(str);
	std::cout << "new string after replace and copy is:" << str << std::endl;

	return 0;
}

#endif
