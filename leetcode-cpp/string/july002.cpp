#include <iostream>
#include "switch.h"

using namespace std;

/*
字符替换和复制
删除一个字符串所有的a,并且复制所有的b。注：字符数组足够大。

*/

class Solution {
public:
	void strReplaceCopy(string &s)
	{
		// 先删除a,可以利用原来字符串的空间
		int n = 0, numb = 0;
		int len = s.size();
		// for (int i = 0; s[i] != '\0'; ++i)
		for (int i = 0; i < len; ++i)
		{
			if (s[i] != 'a') { 
				s[n++] = s[i];
			}
			if (s[i] == 'b') { ++numb; }
		}
		for(int i = n; i < len; i++)
			s[i] = '\0';

		// 复制b，采用从后向前的处理顺序
		int newLen = n + numb;
		s[newLen] = '\0';
		for (int i = newLen - 1, j = n-1; j >= 0; --j)
		{
			s[i--] = s[j];
			if (s[j] == 'b')
				s[i--] = 'b';
		}
	}
};


#ifdef J002
int main()
{
	Solution S;
	string str = "abcdabcdabcdab";
	S.strReplaceCopy(str);
	std::cout << "new string after replace and copy is:" << str << std::endl;

	return 0;
}

#endif
