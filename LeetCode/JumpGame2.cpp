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



 
class Solution {
public:
	/*
	    Time Complexity  : O(n)
	    Space Complexity : O(1)
	    Trick: 
	    	similar method with maximun subarray
	        Basic DP problem, using the "local and global" method.
	        key value is where each element can reach; local is A[i]+i, global is max of local
	    Special Cases : 
	    Summary: 
	*/
    bool canJump(int A[], int n) {
        if(A==NULL || n==0){
            return false;
        }

        int global_reach = A[0];
        for(int i=1; i<n && i<=global_reach; i++){
            global_reach  = max(A[i]+i, global_reach);
        }
        return global_reach>=n-1;
    }



 	/*
	    Time Complexity  : O(n)
	    Space Complexity : O(1)
	    Trick: 
	    	additional thing is you need to check when will you need to jump
	    	it's when you have reached out where old best jump can reach.
	    Special Cases : 
	    Summary: 
	*/   
	int jump(int A[], int n) {
        if(A==NULL || n==0){
            return 0;
        }

        int global_reach = 0;
        int last_reach = 0;
        int minJump = 0;
        for(int i=0; i<n && i<=global_reach; i++){
            if(i>last_reach){
                minJump++;
                last_reach = global_reach;
            }
            global_reach = max(A[i]+i, global_reach);
        }
        if(global_reach<n-1){
            return 0;
        }
        return minJump;
    }
};