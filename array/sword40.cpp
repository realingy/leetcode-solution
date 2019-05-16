//哈希表
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> & unique(vector<int> &nums)
{
    vector<int> ret;
    if(nums.size() == 1)
        return nums;

    //哈系表存放数和出现的次数
    map<int,int> c;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(0 == c.count(nums[i]))
            c[nums[i]] = 1;
        else
        {
            c[nums[i]] += 1;
        }
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(1 == c.count(nums[i]))
            ret.push_back(nums[i]);
    }

    return ret;

#if 0
    vector<int>::iterator it = nums.begin();
    while(it != nums.end())
    {
        if(0 == c.count(*it))
            c[*it] = 1;
        else
        {
            c[*it] += 1;
        }
        ++it;
    }
#endif

#if 0
    vector<int>::iterator it2 = nums.begin();
    while(it2 != nums.end())
    {
        if(c.count(*it2) == 1)
            ret.push_back(*it2);
        ++it2;
    }
#endif

#if 0
    map<int,int>::iterator it2 = count.begin();
    while(it2 != count.end())
    {
        if(it2->second == 1)
            ret.push_back(it2->first);

        ++it2;
    }
#endif
    
}

int main()
{
    int a[] = {1,1,2,2,3,4,4,5,5,6,7,7};
    //vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    vector<int> uni = unique(nums);
    cout << uni[0];
    cout << uni[1];

#if 0
    vector<int>::iterator it = uni.begin();
    while(it != uni.end())
    {
        cout << *it << endl;
    }
#endif
}
