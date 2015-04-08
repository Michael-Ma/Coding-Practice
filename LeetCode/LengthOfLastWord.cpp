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
    Special Cases : 
        care about the tailing space cases!
    Summary: 
        major is to see how would you test you program, and corner cases!
*/ 

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s==NULL || s=='\0'){
            return 0;
        }
        int length = 0;
        while(s[length] != '\0'){
            length++;
        }
        int result = 0;
        //removing all the tail space
        do{
            length--;
        }while(s[length]==' ');
        while(length>=0 && s[length]!=' '){
            length--;
            result++;
        }
        return result;
    }
};

int main(){
    Solution test;
    cout<<test.lengthOfLastWord("q se   ")<<endl;
}