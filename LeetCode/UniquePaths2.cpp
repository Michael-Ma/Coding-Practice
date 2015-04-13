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
#include <climits>
#include <algorithm>
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(mn)
    Space Complexity : O(n)
    Trick: 
        easy DP!
        other solutions: recursion, or simply calculate C(m, n+M)
    Special Cases : 
    Summary: 
*/ 

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0){
            return 0;
        }
        int minLen = m>n ? n:m;
        int maxLen = m>n ? m:n;
        int res[minLen+1];
        //init cases
        memset(res, 0, sizeof(res));
        for(int i=1; i<=minLen; i++){
            res[i]=1;
        }
        for(int i=1; i<maxLen; i++){
            for(int j=1; j<=minLen; j++){
                res[j] = res[j-1]+res[j];
            }
        }
        
        return res[minLen];
    }



    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0){
            return 0;
        }
        int size = obstacleGrid[0].size();
        int res[size+1];
        //init
        memset(res, 0, sizeof(res));
        for(int i=1; i<=size; i++){
            if(obstacleGrid[0][i-1]==1){
                break;
            }else{
                res[i] = 1;
            }
        }
        
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<=size; j++){
                if(obstacleGrid[i][j-1]==1){
                    res[j] = 0;
                }else{
                    res[j] = res[j-1]+res[j];
                }
            }
        }
        return res[size];
    }
};