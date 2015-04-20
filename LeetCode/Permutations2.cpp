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
    Time Complexity  : O(n!)
    Space Complexity : O(n!)
    Trick: 
        1. recursion
        2. iteration
    Special Cases : 
    	for iteration, it's ok to insert after the size()!
    Summary: 
*/
// Permutations 
class Solution1 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0){
            return result;
        }
        
        //init
        vector<int> first;
        first.push_back(num[0]);
        result.push_back(first);
        for(int i=1; i<num.size(); i++){
            vector<vector<int> > newResult;
            for(int j=0; j<result.size(); j++){
                vector<int> cur = result[j];
                //try to insert the new char into every possibile position of previous result
                for(int k=0; k<=cur.size(); k++){  //it's ok to insert after the size()!
                    vector<int> tmp = cur;
                    tmp.insert(tmp.begin()+k, num[i]);
                    newResult.push_back(tmp);
                }
            }
            result = newResult;
        }
        return result;
    }
};



// Permutations  II
class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0){
            return result;
        }
        //in order to remove dup, need to sort it.
        sort(num.begin(), num.end());
        bool isExist[num.size()];
        memset(isExist, 0, sizeof(isExist));
        vector<int> candidate;
        helper(num, candidate, isExist, result);
        return result;
    }
    
    void helper(vector<int> &num, vector<int> &candidate, bool isExist[], vector<vector<int> > &result){
        if(candidate.size() == num.size()){
            result.push_back(candidate);
            return;
        }
        for(int i=0; i<num.size(); i++){
        	//careful about this dup condition!!
            if(i>=1 && !isExist[i-1] && num[i]==num[i-1]){
                continue;
            }
            if(!isExist[i]){
                // case 1 : include num[i]
                candidate.push_back(num[i]);
                isExist[i] = true;
                helper(num, candidate, isExist, result);
                // case 2 : not include num[i]
                candidate.pop_back();
                isExist[i] = false;
            }
        }
    }
};