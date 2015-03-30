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
    Space Complexity : O(logn)
    Trick: 
        using the trick for binary search
    Special Cases : 
    Summary: 
    
*/ 

class PowSolution {
public:
    double pow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        double half = pow(x, n/2);
        if(n%2 == 0){
            return half*half;
        }else if(n > 0){
            return half*x*half;
        }else{
            return half/x*half;
        }
    }
};


class SqrtSolution {
public:
    int sqrt(int x) {
        if(x < 0){
            return -1;
        }else if(x == 0){
            return 0;
        }
        int start = 1;  //careful about divide 0!!
        int end   = x;
        int mid;
        while(start <= end){
            mid = (start+end)/2;
            if( mid<=x/mid && mid+1>x/(mid+1) ){
                return mid;
            }else if(mid < x/mid){
                start = mid+1;
            }else{
                end   = mid-1;
            }
        }
        return mid;
    }
};


int main(){
    PowSolution pTest;
    cout<<pTest.pow(8.88023, 3)<<endl;
    cout<<pow(8.88023, 3)<<endl;

    SqrtSolution sTest;
    cout<<sTest.sqrt(1)<<endl;

}