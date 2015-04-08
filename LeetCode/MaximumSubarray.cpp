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
    Space Complexity : O(1)
    Trick: 
        Basic DP problem, using the "local and global" method.
        local means the solution including current point.
    Special Cases : 
    Summary: 
    http://codeganker.blogspot.com/2014/03/maximum-subarray-leetcode.html#uds-search-results
*/ 

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(A==NULL || n==0){
            return 0;
        }
        int local  = A[0];
        int global = A[0];
        for(int i=1; i<n; i++){
            local  = max(A[i], local+A[i]);
            global = max(local, global);
        }
        return global;
    }
};