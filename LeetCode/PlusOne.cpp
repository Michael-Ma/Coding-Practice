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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        
    Special Cases : 
    	when the highest digit becomes 10, it needs to add a new digit.
    Summary: 
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0){
            return digits;
        }
        int carry = 1;
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i]+carry == 10){
                digits[i] = 0;
                carry = 1;
            }else{
            	digits[i] += carry;
                carry = 0;   
            }
        }
        //need to add a new digit here!
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
	Solution test;
	vector<int> digits;
	digits.push_back(2);
	digits.push_back(9);
	digits.push_back(1);
	vector<int> result = test.plusOne(digits);
	for(int i=0; i<result.size(); i++){
		cout<<result[i];
	}
	cout<<endl;
}