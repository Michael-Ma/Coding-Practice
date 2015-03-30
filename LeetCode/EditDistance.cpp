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
    Time Complexity  : O(n*m)
    Space Complexity : O(2n)
    Trick: 
        comparing with w1[i] with w2[j], if last char is same, edt[i][j] = edt[i-1][j-1]
        otherwise, delete->edt[i][j]=edt[i][j-1]+1; add->edt[i][j]=edt[i][j-1]+1; replace edt[i][j]=edt[i-1][j-1]+1
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        //compare word2 with word1, use word1 as base
        int edtDistance[2][word1.length()+1]; 
        memset(edtDistance, 0, sizeof(edtDistance));
        //set init states, when word2 is empty
        for(int i=0; i<=word1.length(); i++){
            edtDistance[0][i] = i;
        }
        //begin DP calculation
        for(int i=0; i<word2.length(); i++){
            int index = (i+1)%2;
            int preIndex = i%2;
            //set the first state, when word1 is empty, distance is the length of the word2;
            edtDistance[index][0] = i+1;
            for(int j=0; j<word1.length(); j++){
                if(word1[j] == word2[i]){
                    edtDistance[index][j+1] = edtDistance[preIndex][j];
                }else{
                    edtDistance[index][j+1] = min(edtDistance[index][j], min(edtDistance[preIndex][j], edtDistance[preIndex][j+1])) + 1;
                }
            }
        }
        return edtDistance[word2.length()%2][word1.length()];
    }
};