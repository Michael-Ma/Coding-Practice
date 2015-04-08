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
    Space Complexity : O(min(n,m)
    Trick: 
        
    Special Cases : 
    Summary: 
        another typical DP question : combination/permutation. 
        trick is to subproblem to be using part of input to generate/compare/do combination or permutation,
        and see if it's OK to get the result.
        think about it! subporblem should be "same" with the original one. don't overthink about it!
        the optimization for space is also quit common:
        if you will only use the info from previous or previous+the one before previous, you can reduce the 2 dimension array
        to 1 or 2 dimension array.
        res ->      [0, min]   // 0 actually is started from min is empty, and max is fully used to compare
        length -> max + min    // first max is actually computed before, no need to compute again
        http://codeganker.blogspot.com/2014/04/interleaving-string-leetcode.html
*/ 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        string minStr = s1.size()>s2.size() ? s2 : s1;
        string maxStr = s1.size()>s2.size() ? s1 : s2;
        bool res[minStr.size()+1];
        //init
        res[0] = true;
        //for the very start for maxStr, which is empty.
        //careful that j=0 means at least 1 char in str
        for(int j=0; j<minStr.size(); j++){
            res[j+1] = res[j]&&(s3[j]==minStr[j]);
        }
        for(int i=0; i<maxStr.size(); i++){
            //for the very start for minStr, which is empty
            res[0] = res[0]&&(s3[i]==maxStr[i]);
            for(int j=0; j<minStr.size(); j++){
                res[j+1] = res[j]&&(s3[i+j+1]==minStr[j]) // it's current char match
                           || res[j+1]&&(s3[i+j+1]==maxStr[i]); // res[j+1] is for i-1 iteration
            }
        }
        return res[minStr.size()];
    }
};
