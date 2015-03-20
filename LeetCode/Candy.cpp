#include <sstream>
#include <stdio.h>
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
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    	start from left, then start from right.
    	start from left, there are some nodes not qualify the requirement, like (3,2,1,4,5,3) -> (1,1,1,2,3,1)
    	but we you search from right to left, those nodes will be corrected.
    	This is a kind of DP!!
    Special Cases : 
   		careful about the start point! for both left and right
    Summary: 
    
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int result = 0;
        if(ratings.size() == 0){
            return result;
        }
        int candyNum[ratings.size()];
        memset(candyNum, 0, sizeof(candyNum));
        
        //first calculate the min num of candy when calculate from left.
        //give first chlid in left 1 candy!
        candyNum[0] = 1;
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                candyNum[i] = candyNum[i-1] + 1;
            }else{
                candyNum[i] = 1;
            }
        }
        
        //now update the num of candy by calculating from right.
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candyNum[i] = max(candyNum[i], candyNum[i+1]+1);
            }
        }
        
        //calculate the whole result;
        for(int i=0; i<ratings.size(); i++){
            result += candyNum[i];
        }
        return result;
    }
};

