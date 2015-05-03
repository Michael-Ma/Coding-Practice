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
//#include <unordered_set> 
//#include <unordered_map>

using namespace std;


// Definition for binary tree*
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    Special Cases : 
        care about the exit cases! make an example and test!
    Summary: 
*/ 
class Solution {
public:
    int sumNumbers(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        return helper(root, 0);
    }
    int helper(TreeNode *root, int preSum){
        if(root==NULL){
            return preSum;
        }
        preSum = preSum*10 + root->val;
        int left = 0;
        int right = 0;
        if(root->left != NULL){
            left = helper(root->left, preSum);
        }
        if(root->right != NULL){
            right = helper(root->right, preSum);
        }
        if(root->left==NULL && root->right==NULL){
            return preSum;
        }
        return left+right;
    }
};