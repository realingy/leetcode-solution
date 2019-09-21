/**
 * @file leet118.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年05月12日 19时19分05秒
 */

//Pascal's Triangle
//

#if 0
#include "header.h"

vector<vector<int>> pascal(int row)
{
    vector<vector<int>> ret;
    
    if(row <= 0) return ret;
    ret.assign(row, vector<int>(1));
    for(int i = 0; i < row; i++)
    {
        ret[i][0] = 1;
        if(0 == i) continue;
        for(int j = 1; j < i; j++)
        {
            ret[i].push_back(ret[i-1][j-1] + ret[i-1][j]);
        }
        ret[i].push_back(1);
    }

    return ret;
}
#endif

