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
    	since it requires max gap between sorted elements, so we need to sort it anyway.
    	Trick is to use Bucket Sort!
    	Since they are all int, maxElem - minElem should be more than 1, avg gap is bucketSize=(maxElem - minElem)/size
    	what we need is the max one, no need to calculate every gap, just those above avg.
    Special Cases : 
    Summary: 
    	memset() : Value to be set. The value is passed as an int, 
    	but the function fills the block of memory using the unsigned char conversion of this value.
*/ 

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int result = 0;
        if(num.size() == 0){
            return result;
        }
        //get the min and max of the array
        int minElem = num[0];
        int maxElem = num[0];
        for(int i=1; i<num.size(); i++){
            if(num[i] > maxElem){
                maxElem = num[i];
            }else if(num[i] < minElem){
                minElem = num[i];
            }
        }
        //init bucket sort
        int bucketSize = max(1, (maxElem - minElem)/(int)num.size());
        int bucketNum  = (maxElem - minElem)/bucketSize + 1;
        int bucketMin[bucketNum];
        int bucketMax[bucketNum];
        for(int i=0; i<bucketNum; i++){
        	bucketMin[i] = maxElem+1;
        	bucketMax[i] = minElem-1;
        }
        for(int i=0; i<num.size(); i++){
            int pos = (num[i] - minElem)/bucketSize;
//            cout<<"before :"<<bucketMin[pos]<<", "<<bucketMax[pos]<<endl;
            if(bucketMin[pos] > num[i]){
                bucketMin[pos] = num[i];
            }
            if(bucketMax[pos] < num[i]){
                bucketMax[pos] = num[i];
            }
//            cout<<bucketMin[pos]<<", "<<bucketMax[pos]<<endl;
        }
        //caculate max gap
        int lastMax = bucketMax[0];
        for(int i=0; i<bucketNum; i++){
//        	cout<<bucketMin[i]<<", "<<bucketMax[i]<<endl;
            if(bucketMin[i] != maxElem+1){
                result = max(result, bucketMin[i]-lastMax);
                lastMax = bucketMax[i];
            }
        }
        return result;
    }
};

int main(){
	vector<int> input;
	input.push_back(1);
	input.push_back(10000000);
	Solution test;
	cout<<test.maximumGap(input)<<endl;
	return 0;
}