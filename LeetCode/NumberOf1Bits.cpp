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
        
    Special Cases : 
    Summary: 
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            if(n & 1 == 1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};