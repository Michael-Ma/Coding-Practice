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
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
    	hard to analyize it correctly from math. find the relationship between number on each pos and k.
        http://codeganker.blogspot.com/2014/03/permutation-sequence-leetcode.html#uds-search-results
    Special Cases : 
    Summary: 
        idea about well know algorithm is very important
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n<=0 || k<=0){
            return "";
        }
        
        k--;   //need to update k because rest will start from 0
        string result = "";
        vector<char> remain;
        for(int i=1; i<=n; i++){
            remain.push_back(char('0'+i));
        }
        int factorial = 1;  //(n-1)!
        for(int i=2; i<n; i++){
            factorial *= i;
        }
        int round = n-1;  //from 0 to n-1
        while(round >= 0){
            int index = k/factorial;
            k = k%factorial;
            result.push_back(remain[index]);
            //this element is used, so can't appear in the subproblem anymore.
            remain.earse(remain.begin()+index);
            //factorial also need to be updated for subproblem
            if(round != 0){
                factorial = factorial/round;
            }
            round--;
        }
        return result;
    }
};