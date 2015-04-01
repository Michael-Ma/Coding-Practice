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
        num of zeros = number of 5 in n!
        careful about 5^2, 5^3.. which contains more than one 5!
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        if(n < 0){
            n = abs(n);
        }
        while(n>=5){
            result += n/5;
            n = n/5;
        }
        return result;
    }
};