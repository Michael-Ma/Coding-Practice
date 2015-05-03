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
        no trick, just be patient and careful
    Special Cases : 
    Summary:
*/
// too many corner cases, will skip it.
class Solution {
public:
    bool isNumber(string s) {
        //trim by youself!
        while(s.size()!=0 && s[0]==' '){
            s.erase(s.begin());
        }
        while(s.size()!=0 && s[s.size()-1]==' '){
            s.erase(s.begin()+s.size()-1);
        }
        
        if(s.size() == 0){
            return false;
        }
        
        bool containDot = false;
        bool containE = false;
        if(s[0]!='-' && s[0]!='+' && (s[0]>'9' || s[0]<'0')){
            if(!containE && !containDot && s[0]=='.' && s.size()>1 && s[1]<='9' && s[1]>='0'){
                containDot = true;
            }else{
                return false;
            }
        }
        for(int i=1; i<s.size(); i++){
            if(!containE && !containDot && s[i]=='.'){
                containDot = true;
                //can be "123." or ".34" or "+.8"
                if( (i==s.size()-1 && (s[i-1]=='+' || s[i-1]=='-')) || 
                    (i!=s.size()-1 && (s[i+1]>'9' || s[i+1]<'0') && 
                        (s[i+1]!='E' && s[i+1]!='e')) ){
                    return false;
                }
            }else if(s[i]>'9' || s[i]<'0'){
                if(!containE && (s[i]=='E' || s[i]=='e')){
                    containE = true;
                    if(i==s.size()-1 || 
                    ( ((s[i-1]>'9' || s[i-1]<'0') && s[i-1]!='.') || 
                        ( (s[i+1]>'9' || s[i+1]<'0') && (s[i+1]!='+' && s[i+1]!='-') || (i==s.size()-2 && (s[i+1]=='+' || s[i+1]=='-')) ))){  //can't be "123E" or "-e34"
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    Solution test;
    cout<<test.isNumber("9.")<<endl;
    cout<<test.isNumber(".7")<<endl;
    cout<<test.isNumber("+.7")<<endl;
    cout<<test.isNumber("+.")<<endl;
    cout<<test.isNumber("46.e3")<<endl;
    cout<<test.isNumber("+.e")<<endl;
    cout<<test.isNumber(" 005047e+6")<<endl;
    cout<<test.isNumber("3.5e+3.5e+3.5")<<endl;
}