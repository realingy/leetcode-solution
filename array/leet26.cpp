/*************************************************************************
    > File Name:    leet26.cpp
    > Author:       ingy
    > Mail:         754037927@qq.com 
    > Created Time: 2018年04月08日 星期日 22时45分32秒
    > Brief:        
 ************************************************************************/

//删除排序数组中的重复的元素,返回处理后的数组长度
//example: 
//input: 1->2->2->3->4->5
//output: 1->2->3->4->5
//return: 5

int removeDuplicates(vector<int> nums)
{
	
    if(nums.size() <= 1) 
        return nums.size();

    int j=0;
    for(int i=1; i<nums.size(); ++i)
    {
        //重复元素跳过
        if(nums[j] == nums[i])
            continue;
        A[++j] = A[i];
    }
    return j+1;
}
