//

#include <iostream>
#include <stdio.h>
using namespace std;

void swap(char *p1, char *p2)
{
    char t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void helper(char *str, char *begin)
{
    if(*begin == '\0')
    {
        printf("%s\n", str);
    }
    else
    {
        for(char *p = begin; *p != '\0'; ++p)
        {
            swap(p, begin);
            helper(str, begin+1);
            swap(p, begin);
        }
    }
}

void strPermutation(char *str)
{
    if(!str)
        return;

    helper(str, str);
}

int main(void)
{
    char str[4] = "abc";
    strPermutation(str);

    return 0;
}
