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
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        try to get the first and last integer without memory, tirck is to calculate the result correct.
    Special Cases : 
    Summary:  
*/ 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        //find the highest pos for x
        int div = 1;
        while(div <= x/10){
            div *= 10;
        }
        while(x != 0){
            int high = x/div;
            int low  = x%10;
            x -= high*div;
            x = x/10;
            div = div/100;
            if(high != low){
                return false;
            }
        }
        return true;
    }
};