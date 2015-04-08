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
        recursive to solve all trees' problems!
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL){
            return;
        }
        preOrderFlatten(root);
    }

    //return the leaf node
    TreeNode* preOrderFlatten(TreeNode *root){
        TreeNode* left  = root->left;
        TreeNode* right = root->right;
        if(left==NULL && right==NULL){
            return root;
        }
        //set left node
        root->left  = NULL;
        if(left != NULL){
            root->right = left;
            //traverse left subtree
            root = preOrderFlatten(left);
        }
        if(right != NULL){
            root->right = right;
            //traverse left subtree
            root = preOrderFlatten(right);
        }
        
        return root;
    }
};