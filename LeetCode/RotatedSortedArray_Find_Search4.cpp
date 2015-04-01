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
    Time Complexity  : O(logn) - O(n)
    Space Complexity : O(1)
    Trick: 
        like binary search, but need to check different conditions
        if there are duplicates, need to move pointer one by one, which makes it O(n).
    Special Cases : 
    Summary: 
*/ 

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size() == 0){
            return -1;
        }
        int minRes = num[0];
        int left   = 0;
        int right  = num.size()-1;
        //the final step will be like [0,1] or [1,0] or [10, 10]
        //either one of them is the min, or it's already checked before
        while(left + 1 < right){
            int mid = (left+right)/2;
            if(num[mid] > num[left]){
                minRes = min(minRes, num[left]);
                left = mid+1;
            }else if(num[mid] < num[left]){
                minRes = min(minRes, num[mid]);
                right = mid-1;
            }else{  //case there is dup
                left++;
            }
        }
        minRes = min(minRes, num[left]);
        minRes = min(minRes, num[right]);
        return minRes;
    }



    int search(int A[], int n, int target) {
        int pos   = -1;
        int left  = 0;
        int right = n-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(target == A[mid]){
                pos = mid;
                break;
            }
            if(A[mid] > A[left]){
                if(target>A[mid] || target<A[left]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else if(A[mid] < A[left]){
                if(target<A[mid] || target>=A[left]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{  //case there is dup
                left++;
            }
        }
        return pos;
    }
};