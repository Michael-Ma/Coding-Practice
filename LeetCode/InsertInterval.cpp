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
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    Special Cases : 
        need to think about all the possibility of two intervals overlap.
    Summary: 
    
*/ 

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }
        int index = 0;
        while(index < intervals.size()){
            if(intervals[index].end < newInterval.start){
                result.push_back(intervals[index]);
            }else if(intervals[index].start <= newInterval.end){
                newInterval.start = min(intervals[index].start, newInterval.start);
                newInterval.end = max(newInterval.end, intervals[index].end);
                index++;
                break;
            }else{
                break;
            }
            index++;
        }
        while(index<intervals.size() && intervals[index].start <= newInterval.end){
            newInterval.end = max(newInterval.end, intervals[index].end);
            index++;
        }
        result.push_back(newInterval);
        while(index < intervals.size()){
            result.push_back(intervals[index]);
            index++;
        }
        
        return result;
    }
};



int main(){
    Solution test;
    vector<Interval> input;
    input.push_back(Interval(1, 5));
    input.push_back(Interval(6, 7));
    input.push_back(Interval(11, 14));
    input.push_back(Interval(15, 19));
    vector<Interval> res = test.insert(input, Interval(0, 0));
    for(int i=0; i<res.size(); i++){
        cout<<res[i].start<<", "<<res[i].end<<endl;
    }
}