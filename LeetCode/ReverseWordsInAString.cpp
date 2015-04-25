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
        reverse the reversed string.
    Special Cases : 
        care about the requirement for processing those spaces
    Summary: 
*/
class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0){
            return;
        }
        //pre-processing
        //removing the leading and trailing spaces
        while(s.size()!=0 && s[0] == ' '){
            s.erase(s.begin());
        }
        while(s.size()!=0 && s[s.size()-1] == ' '){
            s.erase(s.begin()+s.size()-1);
        }
        //remove multiple spaces
        for(int i=1; i<s.size(); i++){
            if(s[i]==' ' && s[i-1]==' '){
                s.erase(s.begin()+i);
                i--;
            }
        }

        //first reverse the whole string
        int start = 0;
        int end = s.size()-1;
        reverse(s, start, end);
        //second reverse each word sperate by blank
        for(int i=0; i<s.size(); i++){
            //either encounter a space or the end of the string
            if(s[i] == ' '){
                reverse(s, start, i-1);
                start = i+1;
            }else if(i == s.size()-1){
                reverse(s, start, i);
            }
        }
    }
    //reverse string from start to end
    void reverse(string &s, int start, int end){
        while(start < end){
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};

int main(){
    Solution test;
    string s1 = " ";
    test.reverseWords(s1);
    cout<<s1<<"!"<<endl;
    string s2 = "   a   b ";
    test.reverseWords(s2);
    cout<<s2<<"!"<<endl;
}