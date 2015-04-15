#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <cfloat> 
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        Basically global max & local max method, but need to care about the negative number.
        so you need to keep track of both min and max.
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    int maxProduct(int A[], int n) {
         if(n<=0 || A==NULL){
             return 0;
         }
         int result = A[0];
         int minProduct = A[0];
         int maxProduct = A[0];
         for(int i=1; i<n; i++){
             int maxCopy = maxProduct;
             maxProduct = max(max(A[i], maxProduct*A[i]), minProduct*A[i]);
             minProduct = min(min(A[i], minProduct*A[i]), maxCopy*A[i]);
             result = max(result, maxProduct);
         }
         return result;
    }
};