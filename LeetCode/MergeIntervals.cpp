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


// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };



/*
    Time Complexity  : O(nlogn)
    Space Complexity : O(n)
    Trick: 
        need to remember how to write comp() for sort()
    Special Cases : 
    Summary: 
    
*/ 

static bool comp(const Interval& l, const Interval& r){
     return l.start < r.start;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size() == 0){
            return result;
        }
        sort(intervals.begin(), intervals.end(), comp);
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(result[result.size()-1].end >= intervals[i].start){
                result[result.size()-1].end = max(intervals[i].end, result[result.size()-1].end);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

};


int main(){
    Solution test;
    vector<Interval> input;
    input.push_back(Interval(1, 4));
    input.push_back(Interval(2, 5));
    vector<Interval> res = test.merge(input);
    for(int i=0; i<res.size(); i++){
        cout<<res[i].start<<", "<<res[i].end<<endl;
    }
}