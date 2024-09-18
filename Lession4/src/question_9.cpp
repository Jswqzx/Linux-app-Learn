#include <iostream>
#include "../include/question_9.h"

using namespace std;

bool isPalindrome(int x)
{
        if(x < 0) return false;

        int cur = 0, num = x, tail = 0;

        while(num)
        {
            tail = num % 10;

            if( cur > 214748364 || (cur == 214748364 && tail > 7) ) return false;
            
            cur = (cur * 10) + tail;

            num /= 10;
        }

        return cur == x;
}
