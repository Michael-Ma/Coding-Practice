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
//#include <cstdint>
//#include <unordered_set> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(1)
    Space Complexity : O(1)
    Trick: 
        1. normal bit operation, only need to care about how many times can you move!
        2. for frequet use, we can pre-calculated the result for 1 byte, and store it in hashmap, then you can do a divide and conquer,
        	calculate for each byte and then merge them togehter
        	https://leetcode.com/discuss/32446/c-3ms-solution-with-lookup-table
    Special Cases : 
    Summary: 
        idea about well know algorithm is very important!! Like divide and conquer, it's can be used here,
        and it can be used in big data, like divide data into different machine, and it can be used in server and database,
		to split the database based on location, and it can be used in design, each component should take care of its own functionality.
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n){
        uint32_t result = 0;
        // for 32 bits, you can only move 31 times!!
        for(int i=0; i<32; i++){
        	result <<= 1;
            result |= (n>>i)&1;
        }
        return result;
    }
};

int main(){
	Solution test;
	cout<<test.reverseBits(1)<<endl;
	cout<<test.reverseBits(2147483648)<<endl;
}