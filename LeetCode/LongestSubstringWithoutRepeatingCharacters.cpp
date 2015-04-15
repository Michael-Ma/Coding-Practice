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
#include <cfloat> 
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        1. think about the hashtable/set when you find any need to do comparsion.
        2. analyze the problem: everytime we find a dup char, it means an end for a possible best solution.
        and for next possible solution, the start should just be the first char after the first dup.
        3. this kind of using 2 pointers to solve string/array traversal problem is widely used
    Special Cases : 
    Summary: 
        To solve problem, the most important thing is to find the condition for a solution, the definition of subproblem,
        and when/what indicates that. That's the part of solving a problem, showing your skills and smart.
*/ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int result = 0;
        int start = 0;
        int end = 0;
        set<int> curVisited;
        while(end < s.size()){
            while(end<s.size() && curVisited.find(s[end])==curVisited.end()){
                curVisited.insert(s[end]);
                end++;
            }
            result = max(result, end-start);
            //move to find a new start, which is the first char after the dup char
            while(s[start] != s[end]){
                curVisited.erase(s[start]);
                start++;
            }
            //remove the duplicate char
            curVisited.erase(s[start]);
            start++;
        }
        return result;
    }
};