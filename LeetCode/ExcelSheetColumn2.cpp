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
    Time Complexity  : O(logn)
    Space Complexity : O(logn)
    Trick: 
        need to care about the corner case
        remember to think about the range before submit, care about out of boundary cases!
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    //Question 1
    string convertToTitle(int n) {
        string result = "";
        if(n<=0){
            return result;
        }
        
        do{
            //make the range from 0-25
            n--;
            int remain = n%26;
            n = n/26;
            result.push_back((char)('A'+remain));
        }while(n > 26);
        
        if(n!=0){
            //add the first char as n-1 since it ranges from 1-26
            result.push_back((char)('A'+n-1));
        }
        
        //reverse the result since the order is reversed when insert
        reverse(result.begin(), result.end());
        return result;
    }


    //Question 2
    int titleToNumber(string s) {
        int result = 0;
        for(int i=0; i<s.size(); i++){
            result *= 26;
            result += s[i]-'A'+1;
        }
        return result;
    }
};