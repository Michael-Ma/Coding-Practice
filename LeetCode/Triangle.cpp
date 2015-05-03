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
    Time Complexity  : O(n*m)
    Space Complexity : O(n)
    Trick: 
    	DP, dp[i] indicates path contains [i]. move from the bottom to the top
    Special Cases : 
    Summary:
    	for DP, need to think about which way to go will be easier, from tail to head or from head to tail.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==0 || triangle[0].size()==0){
            return 0;
        }
        int size = triangle.size();
        int sum[size];
        for(int i=0; i<size; i++){
            sum[i] = triangle[size-1][i];
        }
        for(int i=size-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                sum[j] = min(sum[j], sum[j+1]) + triangle[i][j];
            }
        }
        return sum[0];
    }
};
