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
    Time Complexity  : O(n*m) or O(n^2)
    Space Complexity : O(n*m) or O(n^2)
    Trick: 
    	divide into layers, and skip one point for each visit, so that on each side it will go over same number of points.
    Special Cases : 
    	care about the case that m != n, and also n, m are even or odd!
    Summary:
    	for this kind of question about details, you need to draw a graph to find out the pattern, and think about divide
    	into layers.
*/
// Spiral Matrix  
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size()==0 || matrix[0].size()==0){
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int minEdges = min(matrix.size(), matrix[0].size());
        int levelNum = minEdges/2;
        for(int l=0; l<levelNum; l++){
            //for up edge
            for(int i=l; i<n-l-1; i++){
                result.push_back(matrix[l][i]);
            }
            //for right edge
            for(int i=l; i<m-l-1; i++){
                result.push_back(matrix[i][n-l-1]);
            }
            //for down edge
            for(int i=n-l-1; i>l; i--){
                result.push_back(matrix[m-l-1][i]);
            }
            //for left edge
            for(int i=m-l-1; i>l; i--){
                result.push_back(matrix[i][l]);
            }
        }
        //handle when there are odd edges
        if(minEdges%2 == 1){
            if(m > n){
                for(int i=levelNum; i<m-levelNum; i++){
                    result.push_back(matrix[i][levelNum]);
                }
            }else{
                for(int i=levelNum; i<n-levelNum; i++){
                    result.push_back(matrix[levelNum][i]);
                }
            }
        }
        return result;
    }
};



//Spiral Matrix II
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if(n <= 0){
            return result;
        }
        int levelNum = n/2;
        int val = 1;
        //init result
        for(int i=0; i<n; i++){
            vector<int> tmp(n);
            result.push_back(tmp);
        }
        for(int l=0; l<levelNum; l++){
            //for up edge
            for(int i=l; i<n-l-1; i++){
                result[l][i] = val;
                val++;
            }
            //for right edge
            for(int i=l; i<n-l-1; i++){
                result[i][n-l-1] = val;
                val++;
            }
            //for down edge
            for(int i=n-l-1; i>l; i--){
                result[n-l-1][i] = val;
                val++;
            }
            //for left edge
            for(int i=n-l-1; i>l; i--){
                result[i][l] = val;
                val++;
            }
        }
        if(n%2 == 1){
            result[levelNum][levelNum] = val;
        }
        return result;
    }
};