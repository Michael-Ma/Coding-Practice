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
    Space Complexity : O(1)
    Trick: 
        DFS!!
    Special Cases : 
    Summary: 
        idea about well know algorithm is very important
*/
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int count = 0;
        if(grid.size()==0 || grid[0].size()==0){
            return count;
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(visit(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
    bool visit(vector<vector<char> > &grid, int row, int col){
        if(row>=grid.size() || col>=grid[0].size()){
            return false;
        }
        if(grid[row][col] == '1'){
            grid[row][col] = '2';
            if(row+1 < grid.size()){
                visit(grid, row+1, col);
            }
            if(col+1 < grid[0].size()){
                visit(grid, row, col+1);
            }
            if(row-1 >= 0){
                visit(grid, row-1, col);
            }
            if(col-1 >= 0){
                visit(grid, row, col-1);
            }
            return true;
        }
        return false;
    }
};

int main() {

}