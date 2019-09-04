/*************************************************************************
    > File Name:    leet80.cpp
    > Author:       ingy
    > Mail:         754037927@qq.com 
    > Created Time: 2018年04月08日 星期日 22时45分32秒
    > Brief:        
 ************************************************************************/

//删除排序数组中的重复的元素(最多允许重复出现两次),返回处理后的数组长度
//example: 
//input: 1->2->2->2->3->3->4->5
//output: 1->2->2->3->3->4->5
//return: 7

int removeDuplicates(vector<int> nums)
{
	if(nums.size() <= 1) 
		return nums.size();

	int j = 0;
	int count = 0;
	for(int i=1; i<nums.size(); ++i)
	{
		if(nums[j] == nums[i])
		{
			count++;
			if(count < 2)
			{
				A[++j] = A[i];
			}
			else
			{
				A[++j] = A[i];
				count = 0;
			}
		}
	}
	return j+1;
}
