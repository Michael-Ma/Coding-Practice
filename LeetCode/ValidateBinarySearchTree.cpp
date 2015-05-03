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
        1. use inorder traversal, and keep track of the previous node using reference.
        2. keep the max and min boundary for each node. Note: it can't handle the case when there is INT_MIN or INT_MAX in it..
    Special Cases : 
    Summary: 
    
*/ 
class Solution1 {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        TreeNode* pre = NULL;
        return helper(root, pre);  //set NULL to skip the check for first node
    }
    bool helper(TreeNode* root, TreeNode* &pre){
        if(root == NULL){
            return true;
        }
        bool left = helper(root->left, pre);
        if(pre!=NULL && root->val <= pre->val){
            return false;
        }
        pre = root;
        return left && helper(root->right, pre);
    }
};




class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        return helper(root, INT_MIN, INT_MAX);
    }
    bool helper(TreeNode* root, int min, int max){
        if(root == NULL){
            return true;
        }
        if(root->val<=min || root->val>=max){
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};