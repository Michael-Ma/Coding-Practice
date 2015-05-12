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
#include <cfloat> 
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 

    Special Cases : 
    Summary: 
*/


int eggDropTimes(int floors, int eggs){
    if(floors<0 || eggs<=0){
        return 0;
    }

    int dp[floors+1][eggs+1];
    //init values
    for(int i=0; i<=floors; i++){
        for(int j=0; j<=eggs; j++){
            if(i==0){   //no need to try for 0 floor
                dp[i][j] = 0;
            }else if(i==1){   //only need to try 1 for 1 floor
                dp[i][j] = 1;
            }else{  //worst case is to try every floor, like you only have one egg
                dp[i][j] = i;
            }
        }
    }
    for(int i=2; i<=floors; i++){
        for(int j=2; j<=eggs; j++){
            for(int k=1; k<=i; k++){
                int tmpRes = 1+max(dp[i-k][j], dp[k-1][j-1]);
                dp[i][j] = min(dp[i][j], tmpRes);
            }
        }
    }
    return dp[floors][eggs];
}

int main()
{
    cout<<eggDropTimes(36, 2)<<endl;
    return 0;
}