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
    Time Complexity  : O(logm + logn)
    Space Complexity : O(1)
    Trick: 
        Binary search! Do it in 2 dimensions, first is in rows, then in columns.
    Special Cases : 
    Summary: 
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        //quick return if it's out of range.
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[rowLen-1][colLen-1]){
            return false;
        }
        //binary search for rows
        int start = 0;
        int end = rowLen-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(target == matrix[mid][0]){
                return true;
            }else if(target > matrix[mid][0]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        int row = end; //think about when it will exit, then you will get it.
        // careful!!!
        if(row < 0){
            return false;
        }
        //binary search for columns
        start = 0;
        end = colLen-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};