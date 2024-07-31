#include "../include/question_6.h"

#include <vector>
#include <iostream>

using namespace std;

string myConvert(string s, int numRows)
{
    if(1 == numRows) return s;
    vector<string> strArr(numRows,"");
    bool isDown = false;
    int cur = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(0 == cur || numRows - 1 == cur)
            isDown = !isDown;

        strArr[cur] += s[i];

        if(isDown)
            cur++;
        else
            cur--;
        
    }

    string resStr;
    for(int i = 0; i < numRows; ++i)
    {
        resStr += strArr[i];
    }

    return resStr;
}