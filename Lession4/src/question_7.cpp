#include "../include/question_7.h"

int myReverse(int x)
{
    if(!x) return x; 
    int flag = x/x,res = 0;

    while(x)
    {
        int num = x % 10;
        if( res > 214748364 || (res == 214748364 && num > 7) )
            return 0;

        if( res < -214748364 || (res == -214748364 && num < -8) )
            return 0;

        res = (res * 10) + num;

        x /= 10;
    }

    return res * flag;

}