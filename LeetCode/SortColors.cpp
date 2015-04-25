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
    	1. using counting sort!!
    	2. using pointers to swap!
    	http://codeganker.blogspot.com/2014/04/sort-colors-leetcode.html
        https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/02.07.md
    Special Cases : 
    Summary: 
*/
class Solution1 {
public:
    void sortColors(int A[], int n) {
        if(n <= 0){
            return;
        }
        int before1 = 0;  //the pointer before the start of 1s
        int end1 = n-1;   //the pointer after the end of 1s
        int cur = 0;      //cursor moves among those 1s
        //cur move ahead of before1, and after end1, so no need to check value of before1 or end1
        while(end1<n && cur<=end1){
            if(A[cur] == 0){
                swap(A[cur], A[before1]);
                cur++;
                before1++;
            }else if(A[cur] == 1){
                cur++;
            }else{  //A[cur] == 2
                swap(A[cur], A[end1]);
                end1--;  //won't move cur becaue need to check cur again.
            }
        }
    }
};




class Solution2 {
public:
    void sortColors(int A[], int n) {
        if(n <= 0){
            return;
        }
        int end0 = 0;  // the end of 0s
        int end1 = 0;   // the end of 1s
        for(int i=0; i<n; i++){  // i is the end of 2s
        	if(A[i] == 0){
        		A[i] = 2;
        		A[end1] = 1;
        		A[end0] = 0;
        		end1++;
        		end0++;
        	}else if(A[i] == 1){
        		A[i] = 2;
        		A[end1] = 1;
        		end1++;
        	}
        }
    }
};