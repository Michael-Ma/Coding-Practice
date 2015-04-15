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
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        Using the idea of DFS. start from one point and find the max length.
        using hashmap and set to keep track of which one is visited or existed
    Special Cases : 
    Summary: 
        Good questions are coming from basic ideas of well-know algorithm.
        Think BFS, DFS before doing any problem.
*/ 
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int result = 0;
        if(num.size()==0){
            return result;
        }
        
        unordered_map<int, bool> isExist;
        set<int> visited;
        for(int i=0; i<num.size(); i++){
            isExist[num[i]] = true;
        }
        
        for(int i=0; i<num.size(); i++){
            int pivot = num[i];
            if(visited.find(pivot)!=visited.end()){
                continue;
            }
            visited.insert(pivot);
            int prev = pivot-1;
            while(isExist[prev]){
                visited.insert(prev);
                prev--;
            }
            int next = pivot+1;
            while(isExist[next]){
                visited.insert(next);
                next++;
            }
            result = max(result, next-prev-1);
        }
        return result;
    }
};