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
    Space Complexity : O(1)
    Trick: 
        fibonacci sequence
    Special Cases : 
        careful about the init cases
    Summary: 
    
*/


class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0){
            return -1;
        }else if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }
        //set init value
        int f1 = 1;
        int f2 = 2;
        int fn = 0;
        for(int i=3; i<=n; i++){
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        
        return fn;
    }
};