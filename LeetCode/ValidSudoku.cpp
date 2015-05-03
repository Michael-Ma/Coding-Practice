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
    Space Complexity : O(n)
    Trick: 
        brute force
    Special Cases : 
    Summary:
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if(board.size()!=9 || board[0].size()!=9){
            return false;
        }
        //valid each row
        for(int i=0; i<9; i++){
            set<char> dict;
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(dict.find(board[i][j]) != dict.end()){
                        return false;
                    }else{
                        dict.insert(board[i][j]);
                    }
                }
            }
        }
        //valid each col
        for(int i=0; i<9; i++){
            set<char> dict;
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    if(dict.find(board[j][i]) != dict.end()){
                        return false;
                    }else{
                        dict.insert(board[j][i]);
                    }
                }
            }
        }
        //valid each small cell
        for(int row=0; row<9; row+=3){
            for(int col=0; col<9; col+=3){
                set<char> dict;
                for(int i=row; i<row+3; i++){
                    for(int j=col; j<col+3; j++){
                        if(board[i][j] != '.'){
                            if(dict.find(board[i][j]) != dict.end()){
                                return false;
                            }else{
                                dict.insert(board[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};