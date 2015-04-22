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
    Special Cases : 
        1. care about overflow!
        2. care about negative or positive
    Summary: 
*/
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool isNegative = false;
        if(x<0){
            isNegative = true;
        }
        x = abs(x);
        while(x > 0){
            //handle overflow in the beginning
            if(result > (INT_MAX-x%10)/10){
                return 0;
            }
            result *= 10;
            result += x%10;
            x /= 10;
        }
        return isNegative ? -result:result;
    }
};