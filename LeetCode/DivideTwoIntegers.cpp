#include <sstream>
#include <stdio.h>
#include <climits>
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
    Time Complexity  : O(logn)
    Space Complexity : O(1)
    Trick: 
        num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n
        shift left for divisor and do subduction
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if(divisor == 0){  //notice divide 0 will make program overflow
            return INT_MAX;
        }
        if(dividend == INT_MIN){
            if(divisor == 1){
                return INT_MIN;
            }else if(divisor == -1){
                return INT_MAX;
            }
        }
    
        bool isNeg;
        if((dividend>0&&divisor>0) || (dividend<0&&divisor<0)){
            isNeg = false;
        }else{
            isNeg = true;
        }
        long dividend_l = abs((long)dividend);
        long divisor_l  = abs((long)divisor);
        if(dividend_l < divisor_l){
            return 0;
        }
        int n=0;
        while(divisor_l <= (dividend_l>>1)){
            divisor_l <<= 1;
            n++;
        }
        while(n >= 0){
            if(dividend_l >= divisor_l){
                dividend_l -= divisor_l;
                result += 1<<n;
            }
            divisor_l >>= 1;
            n--;
        }
        return isNeg? -result : result;
    }
};

int main(){
    Solution test;
    cout<<test.divide(-1, 1);
}