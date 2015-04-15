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
    Space Complexity : O(m*l)
    Trick: 
        treat each string in L as a char, do it like LongestSubstringWithoutRepeatingCharacters.cpp
        trick is to use 0 to size-1 as start point to cover all the possible scenarios!
    Special Cases : 
        there might be dublicate items in L 
    Summary:
        try to use know method to solve a different problem, need to think about: 1.what is same/similar.
        2.what is different.  3.how to work around those different part, and convert it to a well know one.
    
*/ 
    //  Time Limit Exceeded!!!!
class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        vector<int> result;
        int size = L[0].size();
        int num  = L.size();
        if(S.size()==0 || size==0 || num==0 || S.size()<size*num){
            return result;
        }

        // there may be dublicate items in L!!
        map<string, int> contained;
        for(int i=0; i<num; i++){
            contained[L[i]]++;
        }
        //start point range from 0 to size-1 will cover all kinds of scenarios
        for(int i=0; i<size; i++){
            int start = i;
            int end = i;
            int count = 0;
            map<string, int> tmp = contained;
            while(end <= S.size()-size){
                string next = S.substr(end, size);
                end += size;  //need to move anyway
                if(tmp[next] > 0){
                    tmp[next]--;
                    count++;
                }
                //it means there is a dup before finished.
                else if(contained[next] > 0){
                    //add words back until the first dup
                    string prev = S.substr(start, size);
                    while(prev != next){
                        tmp[prev]++;
                        count--;
                        start += size;
                        prev = S.substr(start, size);
                    }
                    start += size;
                }
                //it means unvalid input, restore everything
                else{
                    start = end;
                    tmp = contained;
                    count = 0;
                }
                
                //when count is full, it means there's a match, add to result and restore everything
                if(count == num){
                    result.push_back(start);
                    start = end;
                    tmp = contained;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    string S = "aaa";
    vector<string> L;
    L.push_back("a");
    L.push_back("b");
    string S2 = "barfoothefoobarman";
    vector<string> L2;
    L2.push_back("foo");
    L2.push_back("bar");

    vector<int> result = test.findSubstring(S, L);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    result = test.findSubstring(S2, L2);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
}