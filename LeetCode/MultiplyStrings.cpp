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
    Time Complexity  : O(mn)
    Space Complexity : O(m+n)
    Trick: 
        consider each pos inside result, think about which integer from each num could play a role in it
        i.e. pos = 5, it may come from (0, 5), (1,4) (2, 3) (3, 2) (4, 1) (5, 0)
        hard part is to get the index correct. because 0 means highest pos, while size-1 means the 0-9 integer
    Special Cases : 
        careful about the first position of the integer, can't be 0!
    Summary: 
    
*/ 
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()==0 || num2.size()==0){
            return "";
        }
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        string result = "";
        int num = 0;
        for(int i=0; i<num1.size()+num2.size(); i++){
            for(int j=0; j<num1.size()&&j<=i; j++){
                if(i-j < num2.size()){
                    int index1 = num1.size()-1-j;
                    int index2 = num2.size()-1-(i-j);
                    num += (num1[index1]-'0') * (num2[index2]-'0');
//                    cout<<num1[index1]<<", "<<num2[index2]<<", "<<num<<endl;
                }
            }
            // the highest position can't be 0
            if(i!=num1.size()+num2.size()-1 || num>0){
                result.push_back('0'+num%10);
//                 cout<<"0+num%10 ="<<char('0'+num%10)<<endl;
            }
            num = num/10;
//            cout<<num<<endl;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution test;
//    cout<<test.multiply("1", "1")<<endl;
//    cout<<test.multiply("9", "9")<<endl;
    cout<<test.multiply("9", "98")<<endl;
}