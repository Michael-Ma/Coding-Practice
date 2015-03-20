#include <sstream>
#include <stdio.h>
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
    Time Complexity  : O(n^n) -> C(k, n)
    Space Complexity : O(n^n)
    Trick: 
        need to pass result's reference since each recursion may generate 1-n results
        and need to remember remove the added item after return from recursion
    Special Cases : 
    Summary: 
    
*/

class Combinations{
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > resultSum;
        vector<int>          result;
        if(n<k || n<=0 || k<=0 ){
            return resultSum;
        }
        getCombine(1, n, k, result, resultSum);
        return resultSum;
    }
    
    void getCombine(int start, int end, int k, vector<int>& result, vector<vector<int> >& resultSum){
        if(result.size() == k){
            resultSum.push_back(result);
            return;
        }
        for(int i=start; i<=end; i++){
            result.push_back(i);
            getCombine(i+1, end, k, result, resultSum);
            result.pop_back();
        }
    }
};



/*
    Time Complexity  : O(n^n) -> C(k, n)
    Space Complexity : O(n^n)
    Trick: 
        need to pass result's reference since each recursion may generate 1-n results
        and need to remember remove the added item after return from recursion
    Special Cases : 
        need to care about the dup situation, when input has dups, you need to skip it!
    Summary: 
    
*/
class CombinationSum  {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int>          combination;
        if(candidates.size() == 0){
            return result;
        }
        sort(candidates.begin(), candidates.end());
        getCombinations(candidates, target, 0, combination, result);
        return result;
    }
    
    void getCombinations(vector<int> &candidates, int target, int start, vector<int> &combination, vector<vector<int> > &result){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            //care about dup in candidates, it will cause dup in result.
            if(i>=1 && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target >= candidates[i]){
                combination.push_back(candidates[i]);
                getCombinations(candidates, target-candidates[i], i, combination, result);
                combination.pop_back();
            }
        }
    }
};




/*
    Time Complexity  : O(n^n) -> C(k, n)
    Space Complexity : O(n^n)
    Trick: 
        the major difference with the first one is that this one will start from start, 
        and need to check start from start
    Special Cases : 
    Summary: 
    
*/
class CombinationSumII {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int>          combination;
        if(num.size() == 0){
            return result;
        }
        sort(num.begin(), num.end());
        getCombinations(num, target, 0, combination, result);
        return result;
    }
    
    void getCombinations(vector<int> &candidates, int target, int start, vector<int> &combination, vector<vector<int> > &result){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            //care about dup in candidates, it will cause dup in result.
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target >= candidates[i]){
                combination.push_back(candidates[i]);
                getCombinations(candidates, target-candidates[i], i+1, combination, result);
                combination.pop_back();
            }
        }
    }
};