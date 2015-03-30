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
        like DP, f(n) = f(n-1) + f(n-2), while under some situations, it will be f(n)=f(n-1) or f(n)=f(n-2)
    Special Cases : 
        for 00-09, 10, 20, 11-16 21-26, 17-19,
    Summary: 
    
*/ 


class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        if(s.size()==0 || s[0]=='0'){  //start with 0 can't be matched with any one
            return 0;
        }
        int fn = 1; //f(n)
        int fn1 = 1; //f(n-1)
        int fn2 = 1; //f(n-2)
        for(int i=1; i<s.size(); i++){
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                    fn = fn2;
                }else{ //can't be decoded
                    return 0;
                }
            }
            else if(s[i]<='6'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                     fn = fn1+fn2;
                }else{
                    fn = fn1;
                }
            }
            else{
                if(s[i-1]=='1'){
                     fn = fn1+fn2;
                }else{
                    fn = fn1;
                }
            }
            fn2 = fn1;
            fn1 = fn;
        }
        
        return fn;
    }
};