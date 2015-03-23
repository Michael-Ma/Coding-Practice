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
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(1)
    Space Complexity : O(1)
    Trick: 
        need to remember it's ccomparing version number, not simply converting to double/float!
        major part is the special case handling.
        main idea is to split by dot, and comparing with the int between dots, and handle pure 0 case.
    Special Cases : 
        remember "000.0" and "0000" have no difference.
    Summary: 
    
*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        string remian1 = version1;
        string remian2 = version2;
        do{
            int v1 = getIntBeforeDot(remian1);
            int v2 = getIntBeforeDot(remian2);
            if(v1 > v2){
                return 1;
            }else if(v1 < v2){
                return -1;
            }
        }while(remian1.size()!=0 && remian2.size()!=0);
        
        if(remian1.size()!=0){
            if(!checkAllZero(remian1)){
                return 1;
            }
        }else if(remian2.size()!=0){
            if(!checkAllZero(remian2)){
                return -1;
            }
        }
        
        return 0;
    }
    
    int getIntBeforeDot(string &input){
        int pos = input.find('.');
        string before = "";
        if(pos < input.size()){
            before = input.substr(0, pos);
            input = input.substr(pos+1);
        }else{
            before = input;
            input = "";
        }
        return atoi(before.c_str());
    }
    
    bool checkAllZero(string &input){
        for(int i=0; i<input.size(); i++){
            if(input[i] != '0' && input[i] != '.'){
                return false;
            }
        }
        return true;
    }
};


int main(){
    string input1 = "1.1";
    string input2 = "1.10";
    string input3 = "1.10.00";
    string input4 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    string input5 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    Solution test;
    cout<<test.compareVersion(input1, input2)<<endl;
    cout<<test.compareVersion(input2, input3)<<endl;
    cout<<test.compareVersion(input4, input5)<<endl;
}