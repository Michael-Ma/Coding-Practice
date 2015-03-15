#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n*klog(k)) k is the avg length of string
    Space Complexity : O(n)
    Trick: 
    1. sort every string, and using hashmap for compare, and store string into the hashmap
    Special Cases : 
    Summary: 
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string> > mappedResult;
        for(int i=0; i<strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mappedResult[tmp].push_back(strs[i]);
        }
        //pick set of strings with anagrams
        for(map<string, vector<string> >::iterator it=mappedResult.begin(); it!=mappedResult.end(); it++ ){
            int size = it->second.size();
            if(size >= 2){
                for(int i=0; i<size; i++){
                    result.push_back(it->second[i]);
                }
            }
        }
        return result;
    }
};


int main(){
	Solution test;
	vector<string> input;
	input.push_back("abce");
	input.push_back("adecb");
	input.push_back("abcee");
	input.push_back("caebe");
	input.push_back("cabde");
	input.push_back("acdbe");

	vector<string> res = test.anagrams(input);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}
}