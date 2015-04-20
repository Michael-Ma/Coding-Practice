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



class Solution {
public:
/*
    Time Complexity  : O(n^2)
    Space Complexity : O(1)
    Trick: 
        number between 1 are sum of adjacent 2 numbers in previous result;
    Special Cases : 
    Summary: 
*/
    // Pascal's Triangle 
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows <= 0){
            return result;
        }
        
        //init for first row
        vector<int> first;
        first.push_back(1);
        result.push_back(first);
        for(int i=1; i<numRows; i++){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1; j<result[i-1].size(); j++){
                tmp.push_back(result[i-1][j]+result[i-1][j-1]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }



/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
        in order to save space, trick is to do inplace add, 
        because it only use provious element, so we calculate from tail to head
    Special Cases : 
    Summary: 
*/
    // Pascal's Triangle II
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex < 0){
            return result;
        }
        //init
        result.push_back(1);
        for(int i=1; i<=rowIndex; i++){
            for(int j=result.size()-1; j>0; j--){
                result[j] += result[j-1];
            }
            result.push_back(1);
        }
        return result;
    }
};