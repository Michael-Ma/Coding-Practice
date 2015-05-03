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
    	the key to this question is to find the math pattern of this problem, i.e. find the pattern where each char should be in the final result
		basically it's just like a couple of "V", like "VVVVVV"
    Special Cases : 
    	early return for numRows == 1, so that no exceeding memory limit.
    Summary:
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==0 || numRows<=0){
            return "";
        }
        if(numRows == 1){
        	return s;
        }
        string result = "";
        int size = 2*numRows-2;  //size of each "V"!
        for(int i=0; i<numRows; i++){
            for(int j=i; j<s.size(); j+=size){
                result.push_back(s[j]);
                if(i>0 && i!=numRows-1 && (j-i + size-i)<s.size()){
                    result.push_back(s[j-i + size-i]);
                }
            }
        }
        return result;
    }
};