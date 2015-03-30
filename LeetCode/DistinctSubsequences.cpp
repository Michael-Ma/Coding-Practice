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
    Time Complexity  : O(n*m)
    Space Complexity : O(n)
    Trick: 
        DP! main idea is to maintain num of subsequences for S[0-i] and T[0-j]
        if S[i] == T[j], res[i][j] = res[i-1][j-1](when matching the last char of S) + res[i-1][j](when not matching the last char of S)
        else, res[i][j] = res[i-1][j] (can't match the last char in S)
        can save space by using only one dimension array.
    Special Cases : check the comments
    Summary:
*/ 

class Solution {
public:
    int numDistinct(string S, string T) {
        if(T.size() == 0){
            return 1;
        }
        if(S.size() == 0){
            return 0;
        }
        // size need to +1 because 0 is also considered, as init
        int result[T.size()+1];
        memset(result, 0, sizeof(result));  // need to clear memory, otherwise it will be failures!
        result[0] = 1;
        for(int i=0; i<S.size(); i++){
            // since we only use one dimension array, we need to update from the tail to head,
            // because we use only previous data like [j-1], and use it before messing up it.
            for(int j=T.size()-1; j>=0; j--){
                if(S[i] == T[j]){
                    result[j+1] = result[j]+result[j+1];
                }else{
                    result[j+1] = result[j+1];
                }
            }
        }
        return result[T.size()];
    }
};