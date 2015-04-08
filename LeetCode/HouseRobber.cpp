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
        easy DP question. care about init cases will be good
    Special Cases : 
    Summary: 
    
*/ 


class Solution {
public:
    int rob(vector<int> &num) {
        int size = num.size();
        int total[size+1];
        memset(total, 0, size+1);
        // init cases;
        if(size == 0){
            return 0;
        }else if(size == 1){
            return num[0];
        }else{
            total[0] = 0;
            total[1] = num[0];
            for(int i=2; i<=size; i++){
                total[i] = max(total[i-1], total[i-2]+num[i-1]);
            }
        }

        return total[size];
    }
};