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
    Time Complexity  : O(logn)
    Space Complexity : O(1)
    Trick: 
        Basically it's binary search!
        The most difficult part is to understand that binary search always return a correct answer
        because num[-1] = num[n] = -∞. and num[i] ≠ num[i+1], so at least head or tail is peak
    Special Cases : 
    Summary: 
    
*/ 


class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.size() == 0){
            return -1;
        }
        int low  = 0;
        int high = num.size()-1;
        while(low < high){
            int mid = (low+high)/2;
            if(num[mid] < num[mid+1]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;  //low==high
    }
};