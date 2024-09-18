#include <iostream>
#include "../include/question_11.h"

using namespace std;

int maxArea(vector<int>& height)
{
    int area = 0,max = 0,left = 0, right = height.size() -1;
    // cout << "max: " << max << "left:" << left << "right: " << right << endl; 

    while(left != right)
    {
        area = min(height[right],height[left]) * (right - left);

        cout << "Area: " << area << " height: " << min(height[right],height[left]) << " bottom: " << (right - left) << " left: " << left << " right: " << right << endl;
        max = area > max ? area : max;

        if(height[right] <= height[left])
            --right;
        else
            ++left;
    }

    cout << "Max Area: " << max << endl;

    return 0;
}