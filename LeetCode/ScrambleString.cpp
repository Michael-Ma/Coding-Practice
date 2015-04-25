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
    Time Complexity  : O(n^4)
    Space Complexity : O(n^3)
    Trick: 
        http://codeganker.blogspot.com/2014/04/scramble-string-leetcode.html
    Special Cases : 
    Summary: 
    	for multi-dimensional array in c++, got to init in for loop.
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        //assume s1 and s2 have same length
        if(s1.size() != s2.size()){
        	return false;
        }
        if(s1.size() == 0){
            return true;
        }
        bool dp[s1.size()][s2.size()][s1.size()+1]; //s1 start, s2 start, length
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
            	for(int k=0; k<s1.size()+1; k++){
                	dp[i][j][k] = false;
                }
            }
        }
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                dp[i][j][1] = s1[i]==s2[j];
            }
        }
        for(int l=2; l<=s1.size(); l++){
            for(int i=0; i<s1.size()-l+1; i++){
                for(int j=0; j<s2.size()-l+1; j++){
                    for(int k=1; k<l; k++){
                        dp[i][j][l] |= (dp[i][j][k]&&dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k]&&dp[i+k][j][l-k]);
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};