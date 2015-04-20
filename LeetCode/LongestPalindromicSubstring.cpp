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
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
        using DP to save the previous check result. 
        (j-i)<=2 can easly skip those short term corner cases.
    Special Cases : 
    Summary: 
    
*/ 
class Solution1 {
public:
    string longestPalindrome(string s) {
        string result = "";
        if(s.size() == 0){
            return result;
        }
        bool isPalindrome[s.size()][s.size()];
        memset(isPalindrome, 0, sizeof(isPalindrome));
        int maxLen = 0;
        for(int i=s.size()-1; i>=0; i--){
            for(int j=i; j<s.size(); j++){
                if(s[j]==s[i] && ((j-i)<=2 || isPalindrome[i+1][j-1])){
                    isPalindrome[i][j] = true;
                    if(maxLen < j-i+1){
                        maxLen = j-i+1;
                        result = s.substr(i, maxLen);
                    }
                }
            }
        }
        return result;
    }
};




/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
        use every pos as a pivot to get the longest prlindrome
        hard part is to take care of "abba" and "aba" 2 cases. so that's why getPalindrome() will take both left and right
        to make it more generic.
    Special Cases : 
    Summary: 
    
*/ 
class Solution2 {
public:
    string longestPalindrome(string s) {
        string result = "";
        if(s.size() == 0){
            return result;
        }
        if(s.size() == 1){
            return s;
        }
        for(int i=1; i+result.size()/2<s.size(); i++){
            if(s[i] == s[i-1]){
                string tmp = getPalindrome(s, i-1, i);
                 if(tmp.size() > result.size()){
                    result = tmp;
                 }
            }
            string tmp = getPalindrome(s, i, i);
            if(tmp.size() > result.size()){
                result = tmp;
            }
        }
        return result;
    }
    string getPalindrome(string& s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        } 
        return s.substr(left+1, right-left-1);
    }
};