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
#include <functional>
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(m+n)
    Space Complexity : O(1)
    Trick: 
        to avoid swap additional chars, you can start from the tail and move to the head
    Special Cases : 
    Summary:  
*/ 
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1, j=n-1;
        while(i>=0 && j>=0){
            if(A[i] > B[j]){
                A[i+j+1] = A[i];
                i--;
            }else{
                A[i+j+1] = B[j];
                j--;
            }
        }
        while(j>=0){
            A[j] = B[j];
            j--;
        }
    }
};