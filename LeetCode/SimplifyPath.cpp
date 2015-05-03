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
    Space Complexity : O(n)
    Trick: 
        use stack will be fine
    Special Cases : 
        need to take care of special cases like ".", "..", "//"
    Summary:
*/
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0){
            return "";
        }
        stack<string> pathSt;
        string token = "";
        for(int i=0; i<path.size(); i++){
            if(path[i] != '/'){
                token.push_back(path[i]);
            }
            //handle case like "/home/../foo/"
            else if(token == ".."){
                if(!pathSt.empty()){
                    pathSt.pop();
                }
                token.clear();
            }
            //handle case like "/home/./foo/"
            else if(token == "."){
                token.clear();
            }
            //handle case like "/home//foo/"
            else if(token.size() != 0){
                pathSt.push(token);
                token.clear();
            }
        }
        //need to think about what happens after it exits
        if(token.size()!=0 && token!="."){
            if(token == ".."){
                if(!pathSt.empty()){
                    pathSt.pop();
                }
            }else{
                pathSt.push(token);
            }
        }
        //now output the result
        string result = "";
        while(!pathSt.empty()){
            result = "/" + pathSt.top() + result;
            pathSt.pop();
        }
        //at least return "/"
        if(result.size() == 0){
            result.append("/");
        }
        return result;
    }
};