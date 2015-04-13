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
#include <cfloat> 
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        using a stack to keep track of the increasing elements in a list
        once reaching a smaller element, it means time to compute area for the current biggest one
    Special Cases : 
    Summary: 
    
*/ 
class Solution1 {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0){
            return 0;
        }
        int result = 0;
        stack<int> minPos;
        for(int i=0; i<height.size(); i++){
            //everytime the next is not bigger, it means it's time to calculate the max for the current biggest element
            while(!minPos.empty() && height[i]<height[minPos.top()]){
                int index = minPos.top();
                minPos.pop();
                //result for using this biggest element as base, calculate area
                int localMax = minPos.empty() ? height[index]*i : height[index]*(i-1 - minPos.top());
                result = max(result, localMax);
            }
            minPos.push(i);
        }
        while(!minPos.empty()){
            int index = minPos.top();
            minPos.pop();
            // i = height.size()
            int localMax = minPos.empty() ? height[index]*height.size() : height[index]*(height.size()-1 - minPos.top());
            result = max(result, localMax);
        }
        return result;
    }
};



//haven't passed test!!
/*
    Time Complexity  : O(n^2)
    Space Complexity : O(1)
    Trick: 
        use each element as basement, try to find the max possible area based on it.
    Special Cases : 
    Summary: 
    
*/ 
class Solution2 {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0){
            return 0;
        }
        int result = 0;
        for(int i=0; i<height.size(); i++){
            if(i>=1 && height[i]==height[i-1]){
                continue;
            }
            int prev  = i;
            int after = i;
            int base  = height[i];
            while(prev>0 && height[prev]>=base){
                prev--;
            }
            while(after<height.size()-1 && height[after]>=base){
                after++;
            }
            int localMax = base*(after-prev+1);
            result = max(result, localMax);
        }
        return result;
    }
};