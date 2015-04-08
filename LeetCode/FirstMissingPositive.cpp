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
        connect index with value, like A[0]=1, A[1]=2, A[2]=3...
        like using the array as hashmap, but key is the value itself, also as the index of the array
        http://en.wikipedia.org/wiki/Counting_sort
    Special Cases : 
    Summary: 
        Important! If you find there is no way to solve it with limit space, try to modify the input data! 
*/ 



class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(A == NULL || n<1){
            return 1;
        }
        //target value is from 1 to n
        for(int i=0; i<n; i++){
            int pos = A[i];
            while(pos>0 && pos<=n && pos!=A[pos-1]){
                swap(A[i], A[pos-1]);
                pos = A[i];
            }
        }
        for(int i=0; i<n; i++){
            if(A[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};