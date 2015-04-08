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
    Time Complexity  : O(mn)
    Space Complexity : O(1)
    Trick: 
        1. brute force, but need to return early when there is no enough chars
        2. calculate hash. for example, pick the prime number bigger than 26, which is 29, as base.
        "abacd"  ->  hashcode=1+2*29+1*29^2+3*29^3+4*29^4
        http://en.wikipedia.org/wiki/Rolling_hash
    Special Cases : 
    Summary: 
*/


class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(haystack==NULL || needle==NULL){
            return -1;
        }
        string haystack_str(haystack);
        string needle_str(needle);
        if(haystack_str.size() < needle_str.size()){
            return -1;
        }
        
        for(int i=0; i<=haystack_str.size()-needle_str.size(); i++){
            bool matched = true;
            for(int j=0; j<needle_str.size(); j++){
                if(haystack[i+j] != needle[j]){
                    matched = false;
                    break;
                }
            }
            if(matched){
                return i;
            }
        }
        return -1;
    }
};