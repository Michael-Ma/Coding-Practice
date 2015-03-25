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
    Time Complexity  : O(n * k)  k is the average length of string
    Space Complexity : O(k)
    Trick: 
        the hard part is to understand the question..
        be careful about convert int to string
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0){
            return "";
        }
        string result = "1";
        //first 2 situations no need to calculate anymore
        for(int i=2; i<=n; i++){
            int count = 1;
            stringstream newStr;
            //notice that the first char is already considered since count=1
            for(int j=1; j<result.size(); j++){
                if(result[j] == result[j-1]){
                    count++;
                }else{
                    newStr<<count;
                    newStr<<result[j-1];
                    count = 1;  //reset count
                }
            }
            //process for the last element
            newStr<<count;
            newStr<<result[result.size()-1];
            result = newStr.str();
        }
        return result;
    }
};