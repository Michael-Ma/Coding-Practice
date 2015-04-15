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
#include <cfloat> 
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(kn)
    Space Complexity : O(kn)
    Trick: 
        using iteration. need to construct a new vector every time.
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0){
            return result;
        }
        result.push_back("");
        unordered_map<char, string> numToChar;
        initMap(numToChar);
        for(int i=0; i<digits.size(); i++){
            char digit = digits[i];
            string digitStr = numToChar[digit];
            vector<string> tmp;
            for(int j=0; j<digitStr.size(); j++){
                for(int k=0; k<result.size(); k++){
                    tmp.push_back(result[k]+digitStr[j]);
                }
            }
            result = tmp;
        }
        return result;
    }
    
    void initMap(unordered_map<char, string>& numToChar){
        numToChar['2'] = "abc";
        numToChar['3'] = "def";
        numToChar['4'] = "ghi";
        numToChar['5'] = "jkl";
        numToChar['6'] = "mno";
        numToChar['7'] = "pqrs";
        numToChar['8'] = "tuv";
        numToChar['9'] = "wxyz";
    }
};