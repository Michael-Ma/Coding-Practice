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
    Space Complexity : O(1)
    Trick: 
        use in-order traversal to compare each node, since it should be increasing order.
        in findSwappedNodes(), some inputs are also output, should use TreeNode*&!!
        hard is how to set pre. but you can think it in a easy way, access each node in order, and set pre accordingly.
    Special Cases : 
    Summary: 
    
*/ 
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL){
            return;
        }
        TreeNode* result1 = NULL;
        TreeNode* result2 = NULL;
        TreeNode* pre     = NULL;
        findSwappedNodes(root, pre, result1, result2);
        if(result1 != NULL){
            int tmp = result1->val;
            result1->val = result2->val;
            result2->val = tmp;
        }
    }
    
    void findSwappedNodes(TreeNode* root, TreeNode* &pre, TreeNode* &result1, TreeNode* &result2){
        if(root->left != NULL){
            findSwappedNodes(root->left, pre, result1, result2);
        }
        if(pre!=NULL && pre->val>root->val){
            if(result1 == NULL){
                result1 = pre;
                result2 = root;
            }else{
                result2 = root;
            }
        }
        pre = root;
        if(root->right != NULL){
            findSwappedNodes(root->right, pre, result1, result2);
        }
    }
};