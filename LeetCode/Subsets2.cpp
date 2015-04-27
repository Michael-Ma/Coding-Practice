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
        1. for non-dup situation, for every element in S, add it to all the previous result.
        2. for dup situation, take dup as a special case, 
    Special Cases : 
    Summary:
*/
// Subsets
class Solution1 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> empty;
        result.push_back(empty);
        if(S.size() == 0){
            return result;
        }
        
        sort(S.begin(), S.end());
        for(int i=0; i<S.size(); i++){
            int size = result.size(); //need to keep copy of size now since it will increase later
            for(int j=0; j<size; j++){
                vector<int> tmpRes = result[j];
                tmpRes.push_back(S[i]);
                result.push_back(tmpRes);
            }
        }
        return result;
    }
};


// Subsets II 
class Solution2 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> empty;
        result.push_back(empty);
        if(S.size() == 0){
            return result;
        }
        
        sort(S.begin(), S.end());
        addNewSubsets(S, 0, 0, result);
        return result;
    }
    
    void addNewSubsets(vector<int> &S, int resStart, int pos, vector<vector<int> > &result){
        int size = result.size();
        for(int i=resStart; i<size; i++){
            vector<int> tmpRes = result[i];
            tmpRes.push_back(S[pos]);
            result.push_back(tmpRes);
        }
        if(pos+1 < S.size()){
            if(S[pos] == S[pos+1]){
                resStart = size;
            }else{
                resStart = 0;
            }
            addNewSubsets(S, resStart, pos+1, result);
        }
    }
};

int main(){

}