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
    Time Complexity  : O(mn)
    Space Complexity : O(n)
    Trick: 
        http://codeganker.blogspot.com/2014/02/regular-expression-matching-leetcode.html
    Special Cases : 
    Summary: 
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0){
            //only when s is also empty, it is true
            return s.size()==0;
        }
        bool match[p.size()+1][s.size()+1];
        for(int i=0; i<=p.size(); i++){
            for(int j=0; j<=s.size(); j++){
                match[i][j] = false;
            }
        }
        //init for condition when both are empty.
        match[0][0] = true;
        
        for(int i=0; i<p.size(); i++){
            //if it's *, it may be match[i+1][0] can be true;
            if(p[i]=='*' && i>=1){
                match[i+1][0] = match[i-1][0] || match[i][0]; 
            }
                    
            for(int j=0; j<s.size(); j++){
                if(p[i] != '*'){
                    match[i+1][j+1] = match[i][j] && (p[i]=='.' || p[i]==s[j]);
                }else{
                    if(i<1){
                        continue;
                    }
                    
                    if(p[i-1] != '.'){
                        //* means appear 0 times, 1 time or multiple times.
                        match[i+1][j+1] = match[i-1][j+1] || match[i][j+1] || (match[i+1][j] && p[i-1]==s[j] && s[j]==s[j-1]);
                    }else{
                        if(match[i-1][j] || match[i][j]){
                            for(int k=j; k<=s.size(); k++){
                                match[i+1][k+1] = true;
                            }
                            break;
                        }
                    }
                }
            }
        }
        return match[s.size()][p.size()];
    }
};

int main(){
    Solution test;
    cout<<test.isMatch("", "a*")<<endl;
    cout<<test.isMatch("a*", "")<<endl;
}