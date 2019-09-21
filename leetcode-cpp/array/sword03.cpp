#include <vector>
#include <iostream>

using namespace std;

//查找数字
bool FindNumber(int *array, int row, int column, int target)
{
    bool ret = false;

    if(array != NULL && row >0 && column > 0) {
        int r = 0;
        int c = column - 1;
        while(r < row && c >= 0)
        {
            if(array[r * column + c] == target) {
                ret = true;
                break;
            }
            else if(array[r * column + c] > target) {
                --c;
            }
            else {
                ++r;
            }
        }
    }

    return ret;
}

