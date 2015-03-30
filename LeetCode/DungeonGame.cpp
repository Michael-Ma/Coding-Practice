#include <sstream>
#include <stdio.h>
#include <climits>
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
!!!! this one exceed time limit!
    Time Complexity  : O(nm)
    Space Complexity : O(nm)
    Trick: 
        DP, calculate from top to down, left to right.
    Special Cases : 
    Summary: 
    
*/ 

class Solution1{
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.size() == 0){
            return 0;
        }else if(dungeon[0].size() == 0){
            return 0;
        }
        int min;
        if(dungeon[0][0] < 0){
        	min = dungeon[0][0];
        }else{
        	min = 0;
        }
        int result = moveToPrincess(dungeon, 0, 0, dungeon[0][0], min);
        return -result+1;
    }
    
    int moveToPrincess(vector<vector<int> > &dungeon, int x, int y, int preHealth, int preMinHealth){
        //if reached the princess
        if(y==dungeon.size()-1 && x==dungeon[0].size()-1){
            return preMinHealth;
        }
        int resDown  = INT_MIN;
        int resRight = INT_MIN;
        //move down
        if(y+1 < dungeon.size()){
        	if(preHealth+dungeon[y+1][x] < preMinHealth){
        		resDown = preHealth + dungeon[y+1][x];
        	}else{
        		resDown = preMinHealth;
        	}
            int newMin = moveToPrincess(dungeon, x, y+1, preHealth+dungeon[y+1][x], resDown);
            resDown = min(resDown, newMin);
//            cout<<"("<<x<<", "<<y+1<<"), resDown = "<<resDown<<endl;
        }
        //move right
        if(x+1 < dungeon[y].size()){
        	if(preHealth+dungeon[y][x+1] < preMinHealth){
        		resRight = preHealth + dungeon[y][x+1];
        	}else{
        		resRight = preMinHealth;
        	}
            int newMin = moveToPrincess(dungeon, x+1, y, preHealth+dungeon[y][x+1], resRight);
            resRight = min(resRight, newMin);
//            cout<<"("<<x+1<<", "<<y<<"), resRight = "<<resRight<<endl;
        }
        return max(resDown, resRight);
    }
};



/*
    Time Complexity  : O(nm)
    Space Complexity : O(m)
    Trick: 
        DP, but calculate from down to top, right to left.
        using one array for each will be enough, because old result is not useful anymore.
        when your calculation moved to j, then j+1 will be last calculated result and j will be the old result!
    Special Cases : 
    	you need at least 1 HP to start, so need to add it before return.
    Summary: 
    
*/ 
class Solution2 {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.size() == 0){
            return 0;
        }else if(dungeon[0].size() == 0){
            return 0;
        }
        int minHP_col[dungeon[0].size()];
        memset(minHP_col, 0, sizeof(minHP_col)/sizeof(int));
        for(int i=dungeon.size()-1; i>=0; i--){ //for each row
            for(int j=dungeon[i].size()-1; j>=0; j--){  //for each column
                if(j==dungeon[i].size()-1 && i==dungeon.size()-1){  //for the init
                    minHP_col[j] = -dungeon[i][j];
                }
                else if(j==dungeon[i].size()-1){  //if it's the last column
                    minHP_col[j] = minHP_col[j] - dungeon[i][j];
                }
                else if(i==dungeon.size()-1){  //if it's the last row
                    minHP_col[j] = minHP_col[j+1] - dungeon[i][j];
                }
                else{
                    minHP_col[j] = min(minHP_col[j+1], minHP_col[j]) - dungeon[i][j];
                }
                //reset if gain covers pain
                if(minHP_col[j] < 0){
                    minHP_col[j] = 0;
                }
            }
        }
        
        return minHP_col[0]+1;
    }
    
};


int main(){
	vector<vector<int> > dungeon;
	int x1[] = {-2, -3, 3};
	int x2[] = {-5, -10, 1};
	int x3[] = {10, 30, -5};
	dungeon.push_back(vector<int>(x1, x1+sizeof(x1)/sizeof(int)));
	dungeon.push_back(vector<int>(x2, x2+sizeof(x2)/sizeof(int)));
	dungeon.push_back(vector<int>(x3, x3+sizeof(x3)/sizeof(int)));
	for(int i=0; i<dungeon.size(); i++){
		for(int j=0; j<dungeon[i].size(); j++){
			cout<<dungeon[i][j]<<", ";
		}
		cout<<endl;
	}

	Solution test;
	cout<<test.calculateMinimumHP(dungeon)<<endl;

}
