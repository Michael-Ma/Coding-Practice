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
    Space Complexity : O(n)
    Trick: 
        basically is to test you how to check if there is a loop
        1. use set/hashmap to keep track of all the integer appears before, if there is a hit, means there is a loop
        2. without using memory, use fast/slow pointer to check it.
    Special Cases : 
    Summary:
*/
class Solution {
public:
    bool isHappy(int n) {
        set<int> dic;
        while(n != 1){
            if(dic.find(n) != dic.end()){
                return false;
            }
            dic.insert(n);
            n = cal(n);
        }
        return true;
    }
    
    int cal(int n){
        int result = 0;
        while(n){
            result += pow(n%10, 2);
            n = n/10;
        }
        return result;
    }
};