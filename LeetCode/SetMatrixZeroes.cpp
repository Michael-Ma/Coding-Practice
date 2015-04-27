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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        if you want to use O(1) space, one trick the is to reuse the input data. use the first column and first row to store those
        column and row which should be set to 0, and use 2 bool variable to set first row and column.
    Special Cases : 
    Summary:
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return;
        }
        //using first row and first column to store whether it's 0 or not
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                isFirstRowZero = true;
                break;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                isFirstColZero = true;
                break;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //set first row and column in the end
        for(int i=1; i<matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                for(int j=1; j<matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i=1; i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isFirstRowZero){
            for(int i=0; i<matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(isFirstColZero){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }
};