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
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(m)
    Trick: 
    Special Cases : 
        after first match, it may be possible that removing parts of char will also be a match!
    Summary:
        
    
*/ 

class Solution {
public:
    string minWindow(string S, string T) {
        string result = "";
        if(S.size()==0 || T.size()==0 || S.size()<T.size()){
            return result;
        }

        map<char, int> contained;
        for(int i=0; i<T.size(); i++){
            contained[T[i]]++;
        }
        int count = 0;
        int start = 0;
        int end = 0;
        int minLen = S.size()+1;
        int minStart = 0; //no need to substr everytime!
        for(int end=0; end<S.size(); end++){
            char tt = S[end];
            if(contained.find(tt) != contained.end()){
                if(contained[tt] > 0){
                    count++;
                }
                contained[tt]--;
            }
            //if haven't started yet
            else if(count == 0){
                start = end+1;
//                cout<<"start = "<<start<<endl;
                continue;
            }
//            cout<<"start="<<start<<", end="<<end<<", count="<<count<<endl;
            
            //if find a match
            while(count == T.size()){
                if(minLen > end-start+1){
                    minLen = end-start+1;
                    minStart = start;
//                    cout<<"minLen="<<minLen<<", minStart="<<minStart<<endl;
                }
                //first one should always be contained
                contained[S[start]]++;
                // if there is not enough, then reduce; if there are already some redundent, keep checking
                if(contained[S[start]] > 0){
                    count--;
                }
                start++;
                while(start<end && contained.find(S[start])==contained.end()){
                    start++;
                }
//                cout<<"for next, start="<<start<<", end="<<end<<", count="<<count<<endl;
            }
        }
        // if no match at all
        if(minLen > S.size()){
            return "";
        }
        result = S.substr(minStart, minLen);
        return result;
    }
};

int main(){
    Solution test;
    string S1 = "ab";
    string T1 = "b";
    string S2 = "ADOBECODEBANC";
    string T2 = "ABC";
    cout<<test.minWindow(S1, T1)<<endl;
    cout<<test.minWindow(S2, T2)<<endl;
}