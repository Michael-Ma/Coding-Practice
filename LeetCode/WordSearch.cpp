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
    Time Complexity  : O(mn)
    Space Complexity : O(mn)
    Trick: 
    	overall no trick, just brute force.
    	during the match for each node, use DFS to find each possible solution, and recover shared variable.
    Special Cases : 
    Summary:
*/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0){
            return true;
        }
        if(board.size()==0 || board[0].size()==0){
            return false;
        }
        
        bool** visited = new bool*[board.size()];
        for(int i=0; i<board.size(); i++){
        	visited[i] = new bool[board[0].size()];
            for(int j=0; j<board[i].size(); j++){
                visited[i][j] = false;
            }
        }
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(word[0] == board[i][j]){
                    if(search(board, word, i, j, 0, visited)){
                        return true;
                    }
                }
            }
        }
    }
    
    bool search(vector<vector<char> > &board, string &word, int i, int j, int pos, bool** visited){
        if(pos == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return false;
        }
        if(!visited[i][j] && board[i][j]==word[pos]){
            visited[i][j] = true;
            bool res = search(board, word, i+1, j, pos+1, visited) || search(board, word, i-1, j, pos+1, visited)
                    || search(board, word, i, j+1, pos+1, visited) || search(board, word, i, j-1, pos+1, visited);
            visited[i][j] = false;
            return res;
        }
        return false;
    }
};