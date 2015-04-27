#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
    public:
        int getMostFreqProduct(vector<int> &nums){
            if(nums.size() == 0){
                return 0;
            }
            map<int, int> numCount;
            for(int i=0; i<nums.size(); i++){
                numCount[nums[i]]++;
            }
            int mostFreq = 0;
            int mostFreqCount = 0;
            for(map<int, int>::iterator it=numCount.begin(); it!=numCount.end(); it++){
                if(mostFreqCount < it->second){
                    mostFreqCount = it->second;
                    mostFreq = it->first;
                }
            }
            return mostFreq*mostFreqCount;
        }

};

int main()
{
   cout << "Hello World" << endl; 
   vector<int> nums;
   nums.push_back(1);
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(2);
   nums.push_back(13);
   nums.push_back(13);
   nums.push_back(13);
   Solution test;
   cout<<test.getMostFreqProduct(nums)<<endl;
   return 0;
}

