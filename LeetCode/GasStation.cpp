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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
       any point between the start and failure will be a failure start!
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size()==0 || cost.size()==0 || gas.size()!=cost.size()){
            return -1;
        }
        int startIndex = 0;
        while(startIndex < gas.size()){
            int remainGas  = 0;
            int cur = startIndex;
            int stationNum = 0;
            while(remainGas >= 0){
                remainGas += gas[cur]-cost[cur];
                stationNum++;
                // if we have already make it
                if(remainGas>=0 && stationNum==gas.size()){
                    return startIndex;
                }else if(remainGas<0){
                    break;
                }
                //otherwise move on
                cur++;
                //need to go circuit
                if(cur == gas.size()){
                    cur = 0;
                }
            }
            //exit if already test the last possibile start point
            if(cur < startIndex){
                break;
            }
            //skip those failure points
            startIndex = cur+1;
        }
        return -1;
    }
};

int main(){
    Solution test;
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    vector<int> cost;
    cost.push_back(2);
    cost.push_back(1);
    cout<<test.canCompleteCircuit(gas, cost)<<endl;
}