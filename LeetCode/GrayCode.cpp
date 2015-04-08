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
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        trick is to use iteration. next one = old one + 1 in front of each code.
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if(n < 0){
            return result;
        }
        //init for case n==0
        result.push_back(0);
        for(int i=1; i<=n; i++){
            int size = result.size();
            //add in reverse order
            for(int j=size-1; j>=0; j--){
                result.push_back(result[j] + (1<<(i-1)));
            }
        }
        return result;
    }
};