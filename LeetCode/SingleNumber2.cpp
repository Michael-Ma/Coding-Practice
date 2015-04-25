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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
    	1. for only appear twices, or get odd times appear from even times apprea, using XOR for each one will be good.
        2. count up how many times each bit appears, find those appear not 3 times.
    Special Cases : 
    Summary:
*/

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res ^= nums[i];  //XOR
        }
        return res;
    }
};




class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        if(nums.size() == 0){
            return result;
        }
        //4 bytes has 32 bits
        int bitMap[32];
        memset(bitMap, 0, sizeof(bitMap));
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<32; j++){
                if((nums[i]>>j) & 1){
                    bitMap[j]++;
                }
            }
        }
        for(int i=0; i<32; i++){
            if(bitMap[i]%3 != 0){
                result += (bitMap[i]%3)<<i;
            }
        }
        return result;
    }
};