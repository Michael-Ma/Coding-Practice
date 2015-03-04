#include <sstream>
#include <stdio.h>
#include <string.h>   //for memset
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
    1. optimal = local optimal, global optimal
    2. find all the possibile optimal before ith element
    Special Cases :
    Summary: 
*/

class Solution1{
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0){
            return 0;
        }
        
        int minNum = prices[0];
        int maxNum = prices[0];
        int res = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < minNum){
                minNum = prices[i];
                maxNum = prices[i];
            }else if(prices[i] > maxNum){
                maxNum = prices[i];
                res = max(res, maxNum-minNum);
            }
        }
        return res;
    }
};


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    1. trade it as two seperate 2nd problem, then combine them together. 
    2. global(i,k)  = max(global(i-1,k), local(i, k)), local means has to trade at i
        local(i,k) = max(global(i-1,k-1)+p[i]-p[i-1], local(i-1,k)+p[i]-p[i-1])  trade at i with buy at i-1, or with buy not at i-1
    Special Cases : need to remember to init all the base cases for DP!
    Summary: 

*/
class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1){
            return 0;
        }
        
        int size = prices.size();
        int left[size];
        int right[size];
        //optimal for single transaction from left to right
        left[0] = 0;
        int minNum = prices[0];
        for(int i=1; i<size; i++){
            minNum = min(minNum, prices[i]);
            left[i] = max(left[i-1], prices[i]-minNum);
        }
        //optimal for single transaction from right to left
        right[size-1] = 0;
        int maxNum = prices[size-1];
        for(int i=size-2; i>=0; i--){
            maxNum = max(maxNum, prices[i]);
            right[i] = max(right[i+1], maxNum-prices[i]);
        }
        //go over all the possible combined result for each node
        int result = 0;
        for(int i=0; i<size; i++){
            result = max(result, left[i]+right[i]);
        }
        return result;
    }

    int maxProfit2(vector<int> &prices) {
        if(prices.size() <= 1){
            return 0;
        }

        int size = prices.size();
        int global[3][size];
        int local[3][size];
        //init start point
        for(int i=0; i<size; i++){
            global[0][i] = 0;
            local[0][i] = 0;
        }
        for(int k=1; k<3; k++){
            global[k][0] = 0;
            local[k][0] = 0;
            for(int i=1; i<size; i++){
                local[k][i] = max(global[k-1][i-1]+prices[i]-prices[i-1], local[k][i-1]+prices[i]-prices[i-1]);
                global[k][i] = max(global[k][i-1], local[k][i]);
            }
        }
        return global[2][size-1];
    }
};


/*
    Time Complexity  : O(kn)
    Space Complexity : O(2n)
    Trick: 
    1. when k is big enough, we can trade whenever we need, use a quick slove
    2. r(k, j) =  trade k before j-1, or trade kth at j.
    Special Cases :
    Summary: for jth subevent, trade or not trade. before that part, if trade, try to find the max profit.
*/

class Solution4 {
public:
    int optimalProfit(vector<int> &prices){   //solution3

        if(prices.size() == 0){
            return 0;
        }
        
        int result = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }

    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if(k >= len/2){
            return optimalProfit(prices);
        }
        
        int optiProfit[2][len];   //actually we just use result from last time, so 2 is enough to save space
        memset(optiProfit, 0, sizeof(optiProfit));  //need to remember!
        for(int i=1; i<=k; i++){  //for different k, all the calculation are the same, k is just like a param
            //optiProfit[i%2][0] = 0;  //init states are all from 0
            int curBalance = -prices[0];  //need to make sure for the init state, result you get is the profit.
            for(int j=1; j<len; j++){
                optiProfit[i%2][j] = max(optiProfit[i%2][j-1], prices[j]+curBalance);
                curBalance = max(curBalance, optiProfit[(i-1)%2][j-1]-prices[j]);
            }
        }
        return optiProfit[k%2][len-1];
    }
};

int main()
{
    Solution3 test3;
    vector<int> prices;
    prices.push_back(12);
    prices.push_back(32);
    prices.push_back(02);
    prices.push_back(20);
    prices.push_back(8);
    prices.push_back(33);
    cout<<"MaxProfit for Solution3 is :"<<test3.maxProfit2(prices)<<endl;
}