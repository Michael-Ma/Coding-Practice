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
#include <cfloat> 
#include <climits> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(logn)
    Space Complexity : O(logn)
    Trick: 
        1. merge two array, and return the median
        2. using binary search, but to find the kth element in two array. 
        because for even case, it's easy to handle.
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m<0 || n<0 || A==NULL || B==NULL){
             return -1;
        }
        // median is different for odd and even
        if((m+n)%2 == 1){
            return findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2+1);
        }else{
            return (findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2) + findKthElem(A, 0, m-1, B, 0, n-1, (m+n)/2+1))/2.0;
        }
    }
    
    int findKthElem(int A[], int startA, int endA, int B[], int startB, int endB, int k){
        int sizeA = endA-startA+1;
        int sizeB = endB-startB+1;
        //make sure A is always smaller than B, for easy implementation
        if(sizeA > sizeB){
            return findKthElem(B, startB, endB, A, startA, endA, k);
        }
        if(sizeA == 0){
            return B[startB+k-1];
        }
        if(k == 1){
            return min(A[startA], B[startB]);
        }
        //-1 because all start from 0
        int posA = min(k/2-1, sizeA-1);
        int posB = k-(posA+1)-1;
        if(A[startA+posA] == B[startB+posB]){
            return A[posA];
        }else if(A[startA+posA] < B[startB+posB]){
            return findKthElem(A, startA+posA+1, endA, B, startB, startB+posB, k-posA-1);
        }else{
            return findKthElem(A, startA, endA+posA, B, startB+posB+1, endB, k-posB-1);
        }
    }
};