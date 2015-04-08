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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        1. using hashmap to keep track the appeared times
        2. sort and then return the one in the middle
        3. since the number is more than half, can use variable to keep track of how many times this num appears more than others.
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int result = num[0];
        int additional = 1;

        for(int i=1; i<num.size(); i++){
            if(additional == 0){
                result = num[i];
            }
            if(num[i] == result){
                additional++;
            }else{
                additional--;
            }
        }
        return result;
    }
};