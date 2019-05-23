#include <iostream>

struct ListNode
{
    int m_nKey;
    ListNode * m_pNext;
};

//1. 使用栈结构实现
void PrintListReversingly_Iteratively(ListNode *head)
{
    std::stack<ListNode *> nodes;

    ListNode *pNode = head;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nKey);
        nodes.pop();
    }
}

//2.使用递归实现
void PrintListReversingly_Iteratively2(ListNode *head)
{
    if(head != NULL) {
        if(head->m_pNext != NULL)
        {
            PrintListReversingly_Iteratively2(head->m_pNext);
        }
        printf("%d\t", head->m_nKey);
    }
}



