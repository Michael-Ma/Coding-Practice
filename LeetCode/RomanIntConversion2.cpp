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
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
	    //I 1
	    //V 5
	    //X 10
	    //L 50
	    //C 100
	    //D 500
	    //M 1,000
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
	//Integer to Roman
    string intToRoman(int num) {
    	string result;
        if(num<1 || num>3999){
        	return result;
        }
        int factor = 1000;
        int remain = num;
        std::vector<int> digits;
        while(factor >= 1){
        	int quotient = num/factor;
        	num = num%factor;
        	factor /= 10;
        	digits.push_back(quotient);
        }
        result.append(singleIntToRoman(digits[0], 'M'));
        result.append(singleIntToRoman(digits[1], 'C', 'D', 'M'));
        result.append(singleIntToRoman(digits[2], 'X', 'L', 'C'));
        result.append(singleIntToRoman(digits[3], 'I', 'V', 'X'));
        return result;
    }

	//convert a single integer to Roman, num is 1 to 9
    string singleIntToRoman(int num, const char one, const char five=' ', const char ten=' '){
    	string result;
    	if(num < 4){
    		for(int i=1; i<=num; i++){
    			result.push_back(one);
    		}
    	}else if(num == 4){
    		result.push_back(one);
    		result.push_back(five);
    	}else if(num < 9){
    		result.push_back(five);
    		for(int i=6; i<=num; i++){
    			result.push_back(one);
    		}
    	}else if(num == 9){
    		result.push_back(one);
    		result.push_back(ten);
    	}
    	return result;
    }





	//Roman to Integer 
    int romanToInt(string s) {
        int result = 0;
        if(s.size() == 0){
            return result;
        }
        //init dict for (roman, value) pairs
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;

        for(int i=0; i<s.size(); i++){
            if(i+1<s.size() && dict[s[i]] < dict[s[i+1]]){
                result -= dict[s[i]];
            }else{
                result += dict[s[i]];
            }
        }
        return result;
    }
};

int main(){
	Solution test;
	cout<<test.intToRoman(234)<<endl;
	cout<<test.romanToInt("CCXXXIV")<<endl;
}