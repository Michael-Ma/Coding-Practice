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
        need to think about the init part. j==0, i==0 and i,j both ==0
    Special Cases : 
    Summary: 
        memset() take num of bytes, instead of number of elements!!!
*/ 

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return -1;
        }
        int size = grid[0].size()+1;
        int sum[size];
        memset(sum, 0, sizeof(sum));
        //init for the x axis
        for(int j=1; j<=grid[0].size(); j++){
            sum[j] = sum[j-1] + grid[0][j-1];
        }
        //set it to max because we are doing min()!!
        sum[0] = INT_MAX;
        for(int i=1; i<grid.size(); i++){
            for(int j=1; j<=grid[i].size(); j++){
                sum[j] = min(sum[j-1], sum[j]) + grid[i][j-1];
            }
        }
        return sum[size-1];
    }
};

int main(){
    Solution test;
    vector<int> tmp;
    tmp.push_back(0);
    vector<vector<int> > grid;
    grid.push_back(tmp);
    cout<<test.minPathSum(grid)<<endl;
}