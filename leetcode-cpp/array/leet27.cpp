/*************************************************************************
    > File Name:    leet27.cpp
    > Author:       ingy
    > Mail:         754037927@qq.com 
    > Created Time: 2018年04月08日 星期日 22时45分19秒
    > Brief:        
 ************************************************************************/

//删除数组中的所有的特定元素,返回处理后的数组长度

int removeElement(int A[], int n, int elem)
{
	int j = 0;
	int i = 0;
	for(i=0; i<n; i++)
	{
		if(A[i] == elem)
			continue;
		A[j++] = A[i];
	}
	return j;
}

