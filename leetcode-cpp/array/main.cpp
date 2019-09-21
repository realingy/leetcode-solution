#include "leet01.cpp"

int main()
{
	//1. two sum
	Solution S;
	vector<int> array = { 2, 7, 8, 9 };
	vector<int> res = S.twoSum(array, 9);

	for(int i = 0; i < res.size();  i++) {
		cout << res[i] << " ";
	}

	//for (auto i : res)
	//	cout << i << ' ';


	return 0;
}
