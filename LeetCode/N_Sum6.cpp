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





/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
    Trick: recursion: use two sum to solve three sum
    Special Cases : for duplicate items in the arary, no need to calcuate twice
                    since the first item alreaddy get all the possible solutions
    Summary: 
*/
class threeSumSolution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 2){
            return result;
        }
        sort(num.begin(), num.end());
        for(int i=0; i<num.size()-2; i++){
            if(i>0 && num[i]==num[i-1]){
                continue;
            }
            int target = 0 - num[i];
            vector<vector<int> > result_2sum = twoSumWithDup(num, target, i+1);
            for(int j=0; j<result_2sum.size(); j++){
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(result_2sum[j][0]);
                tmp.push_back(result_2sum[j][1]);
                result.push_back(tmp);
            }
        }
        return result;
    }
    
    //assume input is sorted
    vector<vector<int> > twoSumWithDup(vector<int> &num, int target, int start){
        vector<vector<int> > result;
        if(num.size() <= start+1){
            return result;
        }
        int left  = start;
        int right = num.size()-1;
        while(left < right){
//            cout<<"num[left] = "<<num[left]<<", num[right] = "<<num[right]<<", target = "<<target<<endl;
            if(num[left] + num[right] == target){
                vector<int> tmp;
                tmp.push_back(num[left]);
                tmp.push_back(num[right]);
                result.push_back(tmp);
                left++;
                right--;
                while(left<right && num[left]==num[left-1]){
                    left++;
                }
                while(left<right && num[right]==num[right+1]){
                    right--;
                }
            }else if(num[left] + num[right] < target){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};


/*
    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
    Trick: recursion: use two sum to solve three sum
    Special Cases : for duplicate items in the arary, no need to calcuate twice
                    since the first item alreaddy get all the possible solutions
    Summary: 
*/
class threeSumClosestSolution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sum = 0;
        int delta = 999999;
        if(num.size() < 2){
            return sum;
        }
        sort(num.begin(), num.end());
        for(int i=0; i<num.size()-2; i++){
            if(i>0 && num[i]==num[i-1]){
                continue;
            }
            int newTarget = target - num[i];
            int result_2sum = twoSumWithDup(num, newTarget, i+1);
            int newDelta = abs(newTarget - result_2sum);
            if(newDelta < delta){
                delta = newDelta;
                sum = result_2sum + num[i];
            }
        }
        return sum;
    }
    
    //assume input is sorted
    int twoSumWithDup(vector<int> &num, int target, int start){
        int result = 999999;
        int delta = 999999;
        if(num.size() <= start+1){
            return result;
        }
        int left  = start;
        int right = num.size()-1;
        while(left < right){
            int new_delta = abs(num[left] + num[right] - target);
            if(new_delta == 0){  //early return if get best result
                return target;
            }else if(new_delta < delta){
                delta = new_delta;
                result = num[left] + num[right];
            }

            if(num[left] + num[right] < target){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};



/*
    Time Complexity  : O(n^3)
    Space Complexity : O(n^2)
    Trick: 
    1.recursion: use two sum to solve three sum
    2.construct node contain value and index, get all the possible node pairs, and use two sum to solve. 
        need to check if there is dup by comparing the index.
    Special Cases : for duplicate items in the arary, no need to calcuate twice
                    since the first item alreaddy get all the possible solutions
                    Input : all the same number, like [0,0,0,0]
    Summary: 
    http://codeganker.blogspot.com/2014/04/4sum-leetcode.html
*/
class fourSumSolution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size() < 4){
            return result;
        }
        sort(num.begin(), num.end());
        for(int i=0; i<num.size()-3; i++){
            if(i>0 && num[i]==num[i-1]){
                continue;
            }
            int new_target = target - num[i];
            vector<vector<int> > result_3sum = threeSum(num, new_target, i+1);
            for(int j=0; j<result_3sum.size(); j++){
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(result_3sum[j][0]);
                tmp.push_back(result_3sum[j][1]);
                tmp.push_back(result_3sum[j][2]);
                result.push_back(tmp);
            }
        }
        return result;
    }

    vector<vector<int> > threeSum(vector<int> &num, int target, int start) {
        vector<vector<int> > result;
        if(num.size() < 3){
            return result;
        }
        for(int i=start; i<num.size()-2; i++){
            if(i>start && num[i]==num[i-1]){
                continue;
            }
            int new_target = target - num[i];
            vector<vector<int> > result_2sum = twoSumWithDup(num, new_target, i+1);
            for(int j=0; j<result_2sum.size(); j++){
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(result_2sum[j][0]);
                tmp.push_back(result_2sum[j][1]);
                result.push_back(tmp);
            }
        }
        return result;
    }

    //assume input is sorted
    vector<vector<int> > twoSumWithDup(vector<int> &num, int target, int start){
        vector<vector<int> > result;
        if(num.size() <= start+1){
            return result;
        }
        int left  = start;
        int right = num.size()-1;
        while(left < right){
//            cout<<"num[left] = "<<num[left]<<", num[right] = "<<num[right]<<", target = "<<target<<endl;
            if(num[left] + num[right] == target){
                vector<int> tmp;
                tmp.push_back(num[left]);
                tmp.push_back(num[right]);
                result.push_back(tmp);
                left++;
                right--;
                while(left<right && num[left]==num[left-1]){
                    left++;
                }
                while(left<right && num[right]==num[right+1]){
                    right--;
                }
            }else if(num[left] + num[right] < target){
                left++;
            }else{
                right--;
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

    vector<int> input1;
    input1.push_back(0);
    input1.push_back(0);
    input1.push_back(0);
    input1.push_back(0);

/*
	twoSumSolution test1;
	vector<int> result1;
	result1 = test1.twoSum(input, 7);
	cout<<"index1="<<result1[0]<<", index2="<<result1[1]<<endl;
*/
    threeSumSolution test2;
    vector<vector<int> > result2;
    result2 = test2.threeSum(input);
    cout<<"result2.size() = "<< result2.size() <<endl;
    for(int i=0; i<result2.size(); i++){
        cout<<"("<<result2[i][0]<<", "<<result2[i][1]<<", "<<result2[i][2]<<")"<<endl;
    }

    threeSumClosestSolution test3;
    cout<<"test3.threeSumClosest() = "<<test3.threeSumClosest(input, 1)<<endl;

    fourSumSolution test4;
    vector<vector<int> > result4;
    result4 = test4.fourSum(input, 14);
    cout<<"result4.size() = "<< result4.size() <<endl;
    for(int i=0; i<result4.size(); i++){
        cout<<"("<<result4[i][0]<<", "<<result4[i][1]<<", "<<result4[i][2]<<", "<<result4[i][3]<<")"<<endl;
    }

    result4 = test4.fourSum(input1, 0);
    cout<<"result4.size() = "<< result4.size() <<endl;
    for(int i=0; i<result4.size(); i++){
        cout<<"("<<result4[i][0]<<", "<<result4[i][1]<<", "<<result4[i][2]<<", "<<result4[i][3]<<")"<<endl;
    }
}
