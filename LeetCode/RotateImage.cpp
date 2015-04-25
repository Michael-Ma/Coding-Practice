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
        can't split it into 4 samle squares and rotate, because the boundary maybe rotated twice, which is hard to control!
        only way to work it out is to divide it into layers of squares, do the same thing for each square, i.e. move the 4 edges of each square
    Special Cases : 
    Summary: 
        it's a kind of divide and conquer
        hard to handle the corner case, but you can solve it by make an example.
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return;
        }
        int layerNum = matrix.size()/2;
        for(int i=0; i<layerNum; i++){
            for(int j=i; j<matrix.size()-1-i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i] = tmp;
            }
        }
    }
};

int main(){
    Solution test;

    vector<vector<int> > matrix;
    vector<int> num4;
    for(int i=0; i<4; i++){
        num4.push_back(i);
    }
    matrix.push_back(num4);
    matrix.push_back(num4);
    matrix.push_back(num4);
    matrix.push_back(num4);
    test.rotate(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<", ";
        }
        cout<<endl;
    }

    vector<vector<int> > matrix2;
    vector<int> num5;
    for(int i=0; i<5; i++){
        num5.push_back(i);
    }
    matrix2.push_back(num5);
    matrix2.push_back(num5);
    matrix2.push_back(num5);
    matrix2.push_back(num5);
    matrix2.push_back(num5);
    test.rotate(matrix2);
    for(int i=0; i<matrix2.size(); i++){
        for(int j=0; j<matrix2[i].size(); j++){
            cout<<matrix2[i][j]<<", ";
        }
        cout<<endl;
    }
}