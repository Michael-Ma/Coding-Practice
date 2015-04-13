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
#include <cfloat> 
//#include <unordered_map>

using namespace std;

Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n)
    Trick: 
        using hashmap to store the ratio, because for each time, all those lines come through the same point,
        same ratio means on the same line.
    Special Cases : 
        1. divisor is 0;
        2. points are same/duplicate, which should be a bonus for all the other lines.
        3. care about when it's int, and when it's int.
    Summary: 
    
*/ 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0){
            return 0;
        }
        int result = 1;
        for(int i=0; i<points.size()-1; i++){
            unordered_map<double, int> ratioMap;
            int samePoint = 1;
            for(int j=i+1; j<points.size(); j++){
                double ratio = 0;
                if(points[j].x==points[i].x && points[j].y==points[i].y){
                    samePoint++;
                    continue;
                }else if(points[j].x == points[i].x){
                    ratio = LONG_MAX;
                }else{
                    ratio = (double)(points[j].y-points[i].y) / (double)(points[j].x-points[i].x);
                }
                ratioMap[ratio]++;
            }
            if(ratioMap.empty()){
                result = max(result, samePoint);
            }else{
                for(unordered_map<double, int>::iterator it=ratioMap.begin(); it!=ratioMap.end(); it++){
                    result = max(result, it->second+samePoint);
                }
            }
        }
        return result;
    }
};