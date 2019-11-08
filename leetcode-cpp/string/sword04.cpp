/**
 * @file sword04.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2019年05月17日 09时45分35秒
 */

#include <iostream>

//替换空格
void ReplaceBlank(char string[], int len)
{
    if(string == NULL && len <= 0)
        return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;

    while(string[i] != '\0')
    {
        ++originalLength;

        if(string[i] == ' ')
            ++numberOfBlank;

        ++i;
    }

    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > len)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
}

#ifdef S004
int main()
{

    return 0;
}
#endif

