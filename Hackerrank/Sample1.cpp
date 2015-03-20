#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string nn;
    getline(cin, nn);
    int n = atoi(nn.c_str());
    string line;
    getline(cin, line);
    vector<int> nums;
    int pre_blank = 0;
    cout<<line<<endl;
    const char* cline = line.c_str();
    for(int i=0; i<=line.size(); i++){
        if(cline[i] == ' ' || cline[i] == '\0'){
            string subStr = line.substr(pre_blank, i-pre_blank);
            int tmp = atoi(subStr.c_str());
            nums.push_back(tmp);
            cout<<tmp<<endl;
            pre_blank = i;
        }
    }
    
    int cdif = (nums[nums.size()-1] - nums[0])/n;
    cout<<"cdif = "<<cdif<<endl;
    for(int i=1; i<nums.size(); i++){
        int abb = nums[i] - nums[i-1];
        cout<<"nums[i] = "<<nums[i]<<", abb = "<<abb<<endl;
        if(abb != cdif){
            cout<<(nums[i]+nums[i-1])/2<<endl;
            return (nums[i]+nums[i-1])/2;
        }
    }
    return 0;
}