#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;

/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        move from left and right to the center! common idea, need to remember!
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() == 0){
            return 0;
        }
        int left    = 0;
        int right   = height.size()-1;
        int maxArea = 0;
        while(left < right){
            int leftHeight  = height[left];
            int rightHeight = height[right];
            int minHeight   = min(leftHeight, rightHeight);
            int area = (right - left)*minHeight;
            maxArea  = max(area, maxArea);
            if(leftHeight == minHeight){
                do{
                    left++;
                }while(height[left] < height[left-1]);
            }else{
                do{
                    right--;
                }while(height[right] < height[right+1]);
            }
        }
        return maxArea;
    }
};