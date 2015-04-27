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
    Special Cases : 
        when you move start or end in a loop, careful about it may reach across the broundary!
    Summary:
*/
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0){
            return 0;
        }
        //find the first non whitespace char
        int start = 0;
        while(start<str.size() && str[start]==' '){
            start++;
        }
        //handle - and +
        bool isNegative = false;
        int result = 0;
        if(str[start] == '-'){
            isNegative = true;
            start++;
        }else if(str[start] == '+'){
            start++;
        }
        //calculate value
        while(start < str.size()){
            if(str[start]>='0' && str[start]<='9'){
                int digit = (int)(str[start] - '0');
                if(!isNegative && result > (INT_MAX-digit)/10){
                    return INT_MAX;
                }else if(isNegative && -result < (INT_MIN+digit)/10){
                    //careful here, result can't compare as positive number, because it can't reach 2147483648!
                    return INT_MIN;
                }else{
                    result = result*10 + digit;
                }
            }else{
                break;
            }
            start++;
        }
        return isNegative ? -result:result;
    }
};

int main(){
    Solution test;
    cout<<test.myAtoi("    -00134")<<endl;
}