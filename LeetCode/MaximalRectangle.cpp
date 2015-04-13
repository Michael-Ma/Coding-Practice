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
#include <climits> 
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(m*n)
    Space Complexity : O(n)
    Trick: 
      using DP to generate rectangle based on the matrix
      using largestRectangleArea to calculate the max area for adding each row!
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int result = 0;
        if(matrix.size()==0 || matrix[0].size()==0){
            return result;
        }
        int size = matrix[0].size();
        vector<int> height(size);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<size; j++){
                if(matrix[i][j]=='0'){
                    height[j] = 0;
                }else if(matrix[i][j]=='1'){
                    height[j]++;
                }
            }
            result = max(result, largestRectangleArea(height));
        }
        return result;
    }

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

