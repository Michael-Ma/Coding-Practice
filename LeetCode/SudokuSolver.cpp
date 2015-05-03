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
    Special Cases : 
    Summary:
*/
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if(board.size()!=9 || board[0].size()!=9){
            return;
        }
        addSudokuNum(board, 0, 0);
    }
    
    bool addSudokuNum(vector<vector<char> > &board, int row, int col){
        if(row == 9){
            return addSudokuNum(board, 0, col+1);  //start from 0, access in a fixed order
        }
        if(col == 9){
            return true;
        }
        //for each possible value
        if(board[row][col] == '.'){
            for(int i=0; i<9; i++){
                char target = (char)(i+'1');
                board[row][col] = target;
                if(isValidInput(board, row, col)){
                    if(addSudokuNum(board, row+1, col)){
                        return true;
                    }
                }
                //set value back
                board[row][col] = '.';
                
            }
        }else{
            return addSudokuNum(board, row+1, col);
        }
        return false;
    }
    
    bool isValidInput(vector<vector<char> > &board, int row, int col){
        //check this row
        for(int i=0; i<9; i++){
            if(row!=i && board[i][col]==board[row][col]){
                return false;
            }
        }
        //check this col
        for(int i=0; i<9; i++){
            if(col!=i && board[row][i]==board[row][col]){
                return false;
            }
        }
        //check this cell
        for(int i=(row/3)*3; i<(row/3 + 1)*3; i++){
            for(int j=(col/3)*3; j<(col/3 + 1)*3; j++){
                if((row!=i||col!=j) && board[i][j]==board[row][col]){
                    return false;
                }
            }
        }
    }
};

int main()
{
    
    return 0;
}