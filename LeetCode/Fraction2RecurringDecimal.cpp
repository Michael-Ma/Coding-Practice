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
    Space Complexity : O(n)
    Trick: 
        difficult part is how to handle messy details..
    Special Cases : 
        be careful about int overflow! Talk with interviewer about it!!
        always try to use a bigger range to deal with int.
    Summary: 
        when you need to detect a pattern, you can utilize map for easy compare & store.
*/ 
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if(denominator == 0){
            return result;
        }
        if(numerator == 0){
            return "0";
        }
        map<long, int> indexMap;
        bool isNeg = (numerator^denominator)>>31;                
        if(isNeg){
            result = "-";
        }
        long numerator_l = abs((long)numerator);
        long denominator_l = abs((long)denominator);
        
        long factor = numerator_l/denominator_l;
        long remain = numerator_l%denominator_l;
        result.append(intToStr(factor));
        if(remain != 0){
            result.push_back('.');
        }
        
        stringstream fraction;
        while(remain != 0){
            factor = remain*10/denominator_l;
//            cout<<"factor = "<<factor<<", remain = "<<remain<<", denominator_l = "<<denominator_l<<endl;
            fraction<<factor;
            indexMap[remain] = fraction.str().size()-1;
            remain = remain*10%denominator_l;
            if(indexMap.find(remain) != indexMap.end()){
                string fractionStr = fraction.str();
                int start  = indexMap[remain];
                cout<<start<<endl;
                int length = fractionStr.size()-start;
                result.append(fractionStr.substr(0, start));
                result.append("(");
                result.append(fractionStr.substr(start, length));
                result.append(")");
                return result; 
            }
        }
        result.append(fraction.str());

        return result;
    }
    
    string intToStr(long input){
        stringstream ss;
        ss<<input;
        return ss.str();
    }
};

int main(){
    Solution test;
    cout<<test.fractionToDecimal(1, 99)<<endl;
    cout<<test.fractionToDecimal(-1, 99)<<endl;
    cout<<test.fractionToDecimal(1, 3)<<endl;
    cout<<test.fractionToDecimal(0, -5)<<endl;
    cout<<test.fractionToDecimal(-1, -2147483648)<<endl;
    cout<<test.fractionToDecimal(-2147483648, 1)<<endl;
}
