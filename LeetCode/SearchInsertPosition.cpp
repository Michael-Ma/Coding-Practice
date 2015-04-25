#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <cfloat> 
#include <climits>
//#include <unordered_set> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(logn)
    Space Complexity : O(1)
    Trick: 
        Binary search!
    Special Cases : 
    Summary: 
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(target == nums[m]){
                return m;
            }else if(target > nums[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return r+1;  //same as return l
    }
};