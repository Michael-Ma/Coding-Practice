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
    Time Complexity  : O(nm)
    Space Complexity : O(n)
    Trick: 
    Special Cases : 
    Summary: 
    
*/ 


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;
        if(strs.size() == 0){
            return result;
        }
        
        int index = 0;
        char indexChar;
        bool failed = false;
        
        while(!failed){
            if(strs[0].size() <= index){
                return result;
            }else{
                indexChar = strs[0][index];
            }
            for(int i=1; i<strs.size(); i++){
                if(index>=strs[i].size() || strs[i][index]!=indexChar){
                    failed = true;
                    break;
                }
            }
            result.push_back(indexChar);
            index++;
        }
        return result;
    }
};


int main(){

}