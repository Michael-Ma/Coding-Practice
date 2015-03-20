#include <sstream>
#include <stdio.h>
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
    Space Complexity : O(n)
    Trick: 
        start from left, then start from right.
        start from left, there are some nodes not correct
        but we you search from right to left, those nodes will be corrected.
        This is a kind of DP!!
    Special Cases : 
        careful about the start point! for both left and right
    Summary: 
    
*/
class Solution1 {
public:
    int trap(int A[], int n) {
        int result = 0;
        if(n <= 0){
            return result;
        }
        
        int water[n];
        memset(water, 0, n);

        //find the highest bar from left for each one.
        int highest = A[0];
        water[0]    = highest;
        for(int i=1; i<n; i++){
            highest = max(highest, A[i]);
            water[i] = highest;
        }
        //update the highest bar form right for each one
        highest = A[n-1];
        for(int i=n-1; i>=0; i--){
            highest  = max(highest, A[i]);
            water[i] = min(water[i], highest);
            result += (water[i] - A[i]);
        }
        return result;
    }
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        left & right pointer method!!
        try to find the threshold of water when moving from left to right, or from right to left
    Special Cases : 
    Summary: 
    
*/
class Solution2 {
public:
    int trap(int A[], int n) {
        int result = 0;
        if(n <= 0){
            return result;
        }

        int left  = 0;
        int right = n-1;

        while(left < right){
            int minHigh = min(A[left], A[right]);
            if(minHigh==A[left]){
                //from left side
                while(left<right && A[left]<=minHigh){
                    result += minHigh - A[left];
                    left++;
                }
            }else{ //from right side
                while(left<right && A[right]<=minHigh){
                    result += minHigh - A[right];
                    right--;
                }
            }
        }
        return result;
    }
};
