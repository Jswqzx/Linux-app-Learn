#include "../include/question_5.h"

#include <iostream>

using namespace std;

string longestPalindrome(string s)
{
    int len = -1,index = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        int len1 = getDistance(s,i,i);
        int len2 = getDistance(s,i,i+1);

        int maxLength = max(len1,len2);

        if(len < maxLength)
        {
            len = maxLength;
            if(1 != maxLength)
                index = i;
        }

    }
    index -= (len - 1) / 2;

    string subStr = s.substr(index,len);
    return subStr;
}

int getDistance(string str, int left, int right)
{
    while(left >=0 && right <= str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}