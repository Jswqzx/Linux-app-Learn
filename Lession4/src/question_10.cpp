#include <iostream>
#include "../include/question_10.h"

using namespace std;

bool isMatch(string s,string p)
{
    if(s.size() > 20 || p.size() > 20) return false;

    int strIndex = 0;
    char preRule = '0';

    for(int i = 0; i < p.size(); ++i)
    {
        char rule = p[i];
        if(strIndex < s.size()) return false;
        
        if(rule >= 'a' && rule <= 'z')
        {
            if(s[strIndex] == rule || ( i != p.size() - 1 && p[i + 1] == '*') )
            {
                if( strIndex < s.size() )
                {
                    strIndex++;
                    preRule = rule;   
                }
                else
                    return false;
            }
            else
                break;

        }
        else if(rule == '.')
        {
            if(strIndex < s.size())
            {
                strIndex++;
                preRule = rule;
            }
        }
        else if(rule == '*')
        {
            while ( strIndex < s.size() )
            {
                if(i == p.size() - 1)
                {
                    if(preRule == '.') return true;

                    while(strIndex < s.size())
                    {
                        if(s[strIndex] == preRule)
                            strIndex++;
                        else
                            return false;
                    }
                }
                else if(s[strIndex] == preRule)
                    strIndex++;
                else
                {
                    if(p[i + 1] == '.' || s[strIndex] == p[i + 1])
                        break;
                    else
                        return false;
                }
            }
        }
    }

    return strIndex == s.size();

}