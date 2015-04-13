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
    Space Complexity : O(logn)
    Trick: 
        1. using recursion
        2. use stack to fork recursion
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    // Maximum Depth of Binary Tree
    int maxDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int leftLen  = maxDepth(root->left);
        int rightLen = maxDepth(root->right);
        return max(leftLen, rightLen)+1;
    }


    // Minimum Depth of Binary Tree 
    int minDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int leftLen  = minDepth(root->left);
        int rightLen = minDepth(root->right);
        if(root->left == NULL){
            return rightLen+1;
        }else if(root->right == NULL){
            return leftLen+1;
        }
        return min(leftLen, rightLen)+1;
    }
};