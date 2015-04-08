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


class Solution {
public:

/*
    Generate Parentheses
    Time Complexity  : O(C(n, 2n))
    Space Complexity : O(C(n, 2n))
    Trick: 
        recursion! common method for this kind of quesiton - generating all the possible pairs
        careful about the string formed! can't do modification on the original one.
    Special Cases : 
    Summary: 
    
*/ 

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0){
            return result;
        }
        addParenthesis(0, 0, n, "", result);
        return result;
    }
    
    void addParenthesis(int left, int right, int n, string formed, vector<string> &results){
        if(left==n && right==n){
            results.push_back(formed);
        }
        if(left < n){
            string newFromed = formed;
            newFromed.append("(");
            addParenthesis(left+1, right, n, newFromed, results);
//            cout<<"left="<<left+1<<", right="<<right<<", newFromed="<<newFromed<<endl;
        }
        if(left>right && right<n){
            string newFromed = formed;
            newFromed.append(")");
            addParenthesis(left, right+1, n, newFromed, results);
//            cout<<"left="<<left<<", right="<<right+1<<", newFromed="<<newFromed<<endl;
        }
    }




/*
    Valid Parentheses
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        for pair match kind problem, you can think about using stack!
    Special Cases : 
    Summary: 
    
*/ 
    bool isValid(string s) {
        if(s.size() == 0){
            return false;
        }
        stack<char> bracketStack;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                bracketStack.push(s[i]);
            }else if(s[i]==')'){
                if(!bracketStack.empty() && bracketStack.top()=='('){
                    bracketStack.pop();
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(!bracketStack.empty() && bracketStack.top()=='['){
                    bracketStack.pop();
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(!bracketStack.empty() && bracketStack.top()=='{'){
                    bracketStack.pop();
                }else{
                    return false;
                }
            }
        }
        if(!bracketStack.empty()){
            return false;
        }
        return true;
    }





/*
    Longest Valid Parentheses 
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        for pair match kind problem, you can think about using stack!
        hard part is how to pass the test! how to update the result!
    Special Cases : 
    Summary: 
    
*/     
    int longestValidParentheses(string s) {
        int result = 0;
        if(s.size() < 2){
            return result;
        }
        stack<int> bracketStack;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                bracketStack.push(i);
            }else if(s[i]==')'){
                if(!bracketStack.empty()){
                    bracketStack.pop();
                    if(!bracketStack.empty()){
                        //clever way to get the start point
                        //bracketStack.top() actually is the point before first valid "("
                        result = max(result, i-bracketStack.top());  
                    }else{
                        result = max(result, i+1-start);
                    }
                }else{
                    //actually here result has already been updated before
                    start = i+1;
                }
            }
        }

        return result;
    }

};

int main()
{
    Solution test;
    vector<string> result = test.generateParenthesis(2);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    cout<<test.longestValidParentheses("()(()")<<endl;
}
