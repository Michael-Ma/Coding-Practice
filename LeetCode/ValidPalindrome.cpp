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
    Special Cases : 
    	when you move start or end in a loop, careful about it may reach across the broundary!
    Summary:
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0){
            return true;
        }
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            while(start<end && !isValid(s[start])){
                start++;
            }
            while(end>start && !isValid(s[end])){
                end--;
            }
            if(start<end){
                if(!isSame(s[start], s[end])){
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
    
    bool isValid(char c) const{
        return (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    bool isSame(char l, char r) const{
        if(l>='A' && l<='Z'){
            l = (char)(l+'a'-'A');
        }
        if(r>='A' && r<='Z'){
            r = (char)(r+'a'-'A');
        }
        return l==r;
    }
};