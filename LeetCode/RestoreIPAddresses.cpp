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
    Time Complexity  : O(1)
    Space Complexity : O(n)
    Trick: 
        since it's limited by length, it can't run every possible combinations.
    Special Cases : 
        IP can't start with 0!
        care about the leading "."! like ".0.0.0.0", need to take special care for first char.
    Summary: 
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        if(s.size() < 4){
            return results;
        }
        string res = "";
        splitDigits(s, 0, 0, res, results);
        return results;
    }
    
    void splitDigits(string &s, int start, int segments, string &prevRes, vector<string> &results){
        if(segments == 4){
            if(start < s.size()){
                return;
            }
            results.push_back(prevRes);
            return;
        }
        
        for(int i=start; i<s.size() && i<start+3; i++){
            string seg = s.substr(start, i-start+1);
            if(isValid(seg)){
                string newRes = "";
                if(segments == 0){
                    newRes = seg;
                }else{
                    newRes = prevRes+"."+seg;
                }
                splitDigits(s, i+1, segments+1, newRes, results);
            }
        }
    }
    
    bool isValid(string str){
        if(str.size() > 3){
            return false;
        }
        if(str.size()>1 && str[0]=='0'){ //can't start with 0
            return false;
        }
        int num = atoi(str.c_str());
        if(num<0 || num>255){
            return false;
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<string> result = test.restoreIpAddresses("0000");
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    
}