#include <sstream>
#include <stdio.h>
#include <string.h>   //for memset
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int optimalProfit(vector<int> &prices){
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
    Solution1 test1;
    vector<int> prices;
    prices.push_back(12);
    prices.push_back(32);
    prices.push_back(02);
    prices.push_back(20);
    prices.push_back(8);
    prices.push_back(33);
    cout<<"MaxProfit for Solution1 is :"<<test1.maxProfit(prices)<<endl;
}