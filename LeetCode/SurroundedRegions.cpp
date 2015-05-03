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
    Time Complexity  : O(n*m)
    Space Complexity : O(n+m)
    Trick: 
    	using flood fill algorithm!  flood fill start from the edges, then all node inside will be good
    	analysis for space complexity : think about what's the max size for stack/queue, won't be more than sum of all edges
    Special Cases : 
    Summary:
*/
class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size()<=1 || board[0].size()<=1){
            return;
        }
        //set all the O on edges to be #
        for(int i=0; i<board.size(); i++){
            fillPoint(board, i, 0);
            fillPoint(board, i, board[0].size()-1);
        }
        for(int i=0; i<board[0].size(); i++){
            fillPoint(board, 0, i);
            fillPoint(board, board.size()-1, i);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void fillPoint(vector<vector<char> > &board, int x, int y){
        if(board[x][y] == 'O'){
            board[x][y] = '#';
            queue<int> wList;
            wList.push(x*board[0].size()+y);
            while(!wList.empty()){
                int index = wList.front();
                wList.pop();
                int row = index/board[0].size();
                int col = index%board[0].size();
                if(row>0 && board[row-1][col]=='O'){
                    board[row-1][col] = '#';
                    wList.push((row-1)*board[0].size()+col);
                }
                if(row<board.size()-1 && board[row+1][col]=='O'){
                    board[row+1][col] = '#';
                    wList.push((row+1)*board[0].size()+col);
                }
                if(col>0 && board[row][col-1]=='O'){
                    board[row][col-1] = '#';
                    wList.push(row*board[0].size()+col-1);
                }
                if(col<board[0].size()-1 && board[row][col+1]=='O'){
                    board[row][col+1] = '#';
                    wList.push(row*board[0].size()+col+1);
                }
            }
        }
    }
};