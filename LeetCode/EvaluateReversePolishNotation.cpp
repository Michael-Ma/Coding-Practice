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
        need to push the result into stack as operand!
    Special Cases : 
    Summary: 

http://zh.wikipedia.org/wiki/%E6%B3%A2%E5%85%B0%E8%A1%A8%E7%A4%BA%E6%B3%95
http://zh.wikipedia.org/wiki/%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E7%A4%BA%E6%B3%95
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        if(tokens.size() == 0){
            return result;
        }
        stack<int> operand;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                int right = operand.top();
                operand.pop();
                int left = operand.top();
                operand.pop();
                operand.push(left+right);
            }else if(tokens[i]=="-"){
                int right = operand.top();
                operand.pop();
                int left = operand.top();
                operand.pop();
                operand.push(left-right);
            }else if(tokens[i]=="*"){
                int right = operand.top();
                operand.pop();
                int left = operand.top();
                operand.pop();
                operand.push(left*right);
            }else if(tokens[i]=="/"){
                int right = operand.top();
                operand.pop();
                int left = operand.top();
                operand.pop();
                operand.push(left/right);
            }else{
                operand.push(atoi(tokens[i].c_str()));
            }
        }
        return operand.top();
    }
};
