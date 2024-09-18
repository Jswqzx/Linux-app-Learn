#include "../include/question_8.h"

#include <iostream>

using namespace std;

int myAtoi(string s)
{
    int index = 0,flag = 1,res = 0;
    // 1. discard spaces
    while(s[index] == ' ') index++;
    // 2. find '-' or '+' default '+'
    if(s[index] == '-')
        flag = -1;
    else if(s[index] == '+' || (s[index] <= '9' || s[index] > '0'))
        flag = 1;
    else
        return res;

    if(s[index] == '+' || s[index] == '-')
        index++;

    // 3. jump pre zero
    while(s[index] == '0') index++;
    
    while(index < s.size())
    {
        if(s[index] < '0' || s[index] > '9')
            return res;
            
        if(res > 214748364 || (res == 214748364 && s[index] > '7') )
            return 2147483647;
        else if( res < -214748364 || (res == -214748364 && s[index] > '8'))
            return -2147483648;
        
        cout << (s[index] - '0') * flag << endl;
        res = (res * 10) + ((s[index] - '0') * flag);

        index++;
    }

    return res;
}
