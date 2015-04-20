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
    Summary: 
        if you can't see how to solve the problem directly, you can try out several cases, and you will find the pattern.
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() < 2){
            return;
        }
        
        //find the first non-increasing element.
        int i=num.size()-2;
        for(; i>=0; i--){
            if(num[i]<num[i+1]){
                break;
            }
        }
        //if all elements are increasing, reverse the whole list
        if(i < 0){
            inplaceReverse(num, 0, num.size()-1);
        }else{
            //find the first element that is larger than i
            int j=num.size()-1;
            for(; j>i; j--){
                if(num[j] > num[i]){
                    //swap two elements
                    int tmp = num[i];
                    num[i] = num[j];
                    num[j] = tmp;
                    break;
                }
            }
            
            //reverse all the elements behind j
            if(i+1 < num.size()-1){
                inplaceReverse(num, i+1, num.size()-1);
            }
        }
    }
    
    void inplaceReverse(vector<int> &num, int start, int end){
        while(start < end){
            int tmp = num[start];
            num[start] = num[end];
            num[end] = tmp;
            start++;
            end--;
        }
    }
};

int main(){
	Solution test;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	test.nextPermutation(num);
	for(int i=0; i<num.size(); i++){
		cout<<num[i]<<", ";
	}
	cout<<endl;
}