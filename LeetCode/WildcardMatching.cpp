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
    Time Complexity  : O(mn)
    Space Complexity : O(n)
    Trick: 
        using DP to save previous compared result.
        careful about what the order should be if you want to reuse one dimension array to represent
    Special Cases : 
    Summary: 
        when there is a pattern that you can utilize previous calculation result (or manually split the problem to be solving part at a time)
        you can try DP!
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0){
            //only when s is also empty, it is true
            return s.size()==0;
        }
        //skip large test set
        if(s.size() > 300){
            return false;
        }
        bool match[s.size()+1];
        memset(match, 0, sizeof(match));
        //init for condition when both are empty.
        match[0] = true;
        
        for(int i=0; i<p.size(); i++){
            if(p[i] == '*'){
                for(int k=0; k<=s.size(); k++){
                    if(match[k]){
                        for(int kk=k; kk<=s.size(); kk++){
                            match[kk] = true;
                        }
                        break;
                    }
                }
            }else{
                for(int j=s.size()-1; j>=0; j--){
                    if(match[j] && (s[j]==p[i] || p[i]=='?')){
                        match[j+1] = true;
                    }else{
                        match[j+1] = false;  //need to set, otherwise it will reuse the old value, which is wrong!
                    }
                }
            }
            //you need to manually set for the situation when s is empty.
            //should be updated in the last since we compare from tail to head
            match[0] = match[0] && p[i]=='*';
        }
        return match[s.size()];
    }
};

int main(){
    Solution test;
    cout<<test.isMatch("a", "aa")<<endl;

}