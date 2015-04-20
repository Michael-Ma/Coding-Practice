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
#include <unordered_set> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
        using DP to save previous result, to save some time!
    Special Cases : 
    Summary: 
    
*/
// Word Break 
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size()==0){
            return true;
        }
        if(wordDict.size()==0){
            return false;
        }
        
        bool isSegmentable[s.size()+1];
        memset(isSegmentable, 0, sizeof(isSegmentable));
        isSegmentable[0] = true;
        
        for(int i=0; i<s.size(); i++){
            for(int j=i; j>=0; j--){
                string tmp = s.substr(j, i-j+1);
                if(wordDict.find(tmp)!=wordDict.end() && isSegmentable[j]){
                    isSegmentable[i+1] = true;
                    break;
                }
            }
        }
        return isSegmentable[s.size()];
    }
};




/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
    Trick: 
        usint DP will need a lot of tmp storage, and more complex.
        It's better to use brute force here.
    Special Cases : 
    Summary: 
    
*/
// Word Break II
class Solution2 {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        if(s.size()==0 || wordDict.size()==0){
            return result;
        }

        getMatchedResult(s, wordDict, 0, "", result);
        return result;
    }
    
    void getMatchedResult(string& s, unordered_set<string>& wordDict, int start, string matched, vector<string>& result){
        if(start == s.size()){
            result.push_back(matched);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string tmp = s.substr(start, i-start+1);
            if(wordDict.find(tmp)!=wordDict.end()){
                string newMatched = matched.size()>0 ? tmp:matched+" "+tmp;
                getMatchedResult(s, wordDict, i+1, newMatched, result);
            }
        }
    }
};


int main(){
    unordered_set<string> wordDict;
    wordDict.insert("a");
    Solution test;
    cout<<test.wordBreak("a", wordDict)<<endl;
}