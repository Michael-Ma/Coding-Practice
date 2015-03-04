#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(nlog(n))
    Space Complexity : O(n)
    Trick: 
    1. using hashmap
    2. sort, then use 2 pointers move from head and tail based on the sum vs target
    Special Cases : can't use same number twice!
    Summary: 
*/
class twoSumSolution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	map<int, int> hashmap;
    	vector<int>	  result;

    	for(int i=0; i<numbers.size(); i++){
    		hashmap[numbers[i]] = i+1;
    	}
        for(int i=0; i<numbers.size(); i++){
        	int remain = target - numbers[i];
        	if(hashmap[remain]!=0 && (i+1)!=hashmap[remain]){   //can't use same number twice!
//        		cout<<"index1="<<i+1<<", index2="<<hashmap[remain]<<endl;
        		result.push_back(i+1);
        		result.push_back(hashmap[remain]);
        	}
        }
        return result;
    }
};


int main(){
	vector<int> input;
	input.push_back(21);
	input.push_back(1);
	input.push_back(-9);
	input.push_back(7);
	input.push_back(11);
	input.push_back(14);
	input.push_back(32);
	input.push_back(-2);
	input.push_back(6);

	twoSumSolution test1;
	vector<int> result;
	result = test1.twoSum(input, 7);
	cout<<"index1="<<result[0]<<", index2="<<result[1]<<endl;
}
