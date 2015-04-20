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
        use recursion!
    Special Cases : 
    Summary: 
    
*/
// Palindrome Partitioning
class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > results;
        if(s.size() == 0){
            return results;
        }
        vector<string> result;
        getMatchedResult(s, 0, result, results);
        return results;
    }
    
    void getMatchedResult(string& s, int start, vector<string> result, vector<vector<string> >& results){
        if(start == s.size()){
            results.push_back(result);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s, start, i)){
                string tmp = s.substr(start, i-start+1);
                result.push_back(tmp);
                getMatchedResult(s, i+1, result, results);
                result.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right){
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};




/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
    Trick: 
        use recursion!
    Special Cases : 
        return res[s.size()]-1 because res is num of palindrome, while what we need is cut numbers!
    Summary: 
        for 2 dimension array, can't use memset() to init, bucause it will only get the length of the pointer!
        you need to go into the array, and set one by one!
*/
// Palindrome Partitioning II
class Solution2 {
public:
    int minCut(string s) {
        if(s.size() == 0){
            return 0;
        }
        bool** dict = getPalindromeDict(s);
        int res[s.size()+1];
        memset(res, 0, sizeof(res));
        for(int i=0; i<s.size(); i++){
            // it's the worst senario
            res[i+1] = i+1;
            for(int j=i; j>=0; j--){
                if(dict[j][i]){
                    res[i+1] = min(res[j]+1, res[i+1]);
                }
            }
        }
        return res[s.size()]-1;
    }
    
    bool** getPalindromeDict(string& s){
        int size = s.size();
        bool** dict = new bool*[size];
        for(int i=0; i<size; i++){
            dict[i] = new bool[size];
            for(int j=0; j<size; j++){
                dict[i][j] = false;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            for(int j=i; j>=0; j--){
                if(s[i]==s[j] && (i-j<=2 || dict[j+1][i-1])){
                    dict[j][i] = true;
                }
            }
        }
        return dict;
    }
};

int main() {
    Solution2 test;
    cout<<test.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
}