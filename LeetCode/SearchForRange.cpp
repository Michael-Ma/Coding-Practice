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
    Time Complexity  : O(n^2)
    Space Complexity : O(1)
    Trick: 
        binary search.
        trick is to also use binary search to find the boundary of target!
    Special Cases : 
    Summary: 
*/
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if(nums.size() == 0){
            return result;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(target == nums[m]){
                l = m;
                r = m;
                while(l>=1 && target==nums[l-1]){
                    l--;
                }
                while(r<nums.size()-1 && target==nums[r+1]){
                    r++;
                }
                result.clear();
                result.push_back(l);
                result.push_back(r);
                return result;
            }else if(target < nums[m]){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return result;
    }
};


class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if(nums.size() == 0){
            return result;
        }
        //find the left bounday of target
        int ll = 0;
        int lr = nums.size()-1;
        while(ll <= lr){
            int m = (ll+lr)/2;
            if(target <= nums[m]){
                lr = m-1;
            }else{
                ll = m+1;
            }
        }
        //find the right bounday of target
        int rl = 0;
        int rr = nums.size()-1;
        while(rl <= rr){
            int m = (rl+rr)/2;
            if(target < nums[m]){
                rr = m-1;
            }else{
                rl = m+1;
            }
        }
        if(ll <= rr){
            result[0] = ll;
            result[1] = rr;
        }
        return result;
    }
};