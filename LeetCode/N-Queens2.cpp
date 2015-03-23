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
#include <algorithm>
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(n!)
    Space Complexity : O(n^3)
    Trick: 
        how to traverse in checkAllPossibleSetup()!!!
    Special Cases : 
    Summary: 
    
*/

class NQ1 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if(n <= 0){
            return result;
        }
        
        int column_row[n];
        memset(column_row, -1, n); 
        checkAllPossibleSetup(n, 0, column_row, result);
        return result;
    }
    
    void checkAllPossibleSetup(int n, int start, int column_row[], vector<vector<string> > &result){
        if(start == n){
            result.push_back(genChessboard(n, column_row));
            return;
        }
        for(int i=0; i<n; i++){
            column_row[start] = i;
            if(checkValid(start, column_row)){  
                checkAllPossibleSetup(n, start+1, column_row, result);
            }
        }
    }
    
    vector<string> genChessboard(int n, int column_row[]){
        vector<string> result;
        for(int i=0; i<n; i++){   //for each row
            string newline;
            for(int j=0; j<n; j++){   //for each column
                if(j == column_row[i]){
                    newline.append("Q");
                }else{
                    newline.append(".");
                }
            }
            result.push_back(newline);
        }
        return result;
    }
    
    bool checkValid(int end, int column_row[]){
        for(int i=0; i<end; i++){
            if(column_row[i]==column_row[end] || abs(column_row[i]-column_row[end])==end-i){
                return false;
            }
        }
        return true;
    }
};




/*
    Time Complexity  : O(n!)
    Space Complexity : O(n^3)
    Trick: 
        how to traverse in checkAllPossibleSetup()!!!
    Special Cases : 
    Summary: 
    
*/

class NQ2{
public:
    int totalNQueens(int n) {
       int result = 0;
        if(n <= 0){
            return result;
        }
        
        int column_row[n];
        memset(column_row, -1, n); 
        checkAllPossibleSetup(n, 0, column_row, result);
        return result;
    }
    
    void checkAllPossibleSetup(int n, int start, int column_row[], int &result){
        if(start == n){
            result++;
            return;
        }
        for(int i=0; i<n; i++){
            column_row[start] = i;
            if(checkValid(start, column_row)){  
                checkAllPossibleSetup(n, start+1, column_row, result);
            }
        }
    }

    bool checkValid(int end, int column_row[]){
        for(int i=0; i<end; i++){
            if(column_row[i]==column_row[end] || abs(column_row[i]-column_row[end])==end-i){
                return false;
            }
        }
        return true;
    }
};



int main() {
    NQ1 test;
    vector<vector<string> > result = test.solveNQueens(8);
    for(int i=0; i<result.size(); i++){
        cout<<"[ "<<endl;
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<endl;
        }
        cout<<" ]"<<endl;
    }

    NQ2 test2;
    cout<<"result num = "<<test2.totalNQueens(8)<<endl;
}