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
        1.recursive
        2.iterative
    Special Cases : 
    Summary:  
*/
class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        return checkSymmetric(root->left, root->right);
    }
    
    bool checkSymmetric(TreeNode *left, TreeNode *right){
        if(left==NULL && right!=NULL){
            return false;
        }else if(left!=NULL && right==NULL){
            return false;
        }else if(left==NULL && right==NULL){
            return true;
        }else if(left->val != right->val){
            return false;
        }
        return checkSymmetric(left->right, right->left) && checkSymmetric(left->left, right->right);
    }
};



class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }else if(root->left==NULL || root->right==NULL){
            return false;
        }
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;
        leftQueue.push(root->left);
        rightQueue.push(root->right);
        while(!leftQueue.empty() && !rightQueue.empty()){
            TreeNode* left = leftQueue.front();
            leftQueue.pop();
            TreeNode* right = rightQueue.front();
            rightQueue.pop();
            if(left->val != right->val){
                return false;
            }
            if((left->left!=NULL && right->right==NULL) || (left->left!=NULL && right->right!=NULL)){
                return false;
            }
            if((left->right!=NULL && right->left==NULL) || (left->right==NULL && right->left!=NULL)){
                return false;
            }
            if(left->left!=NULL && right->right!=NULL){
                leftQueue.push(left->left);
                rightQueue.push(right->right);
            }
            if(left->right!=NULL && right->left!=NULL){
                leftQueue.push(left->right);
                rightQueue.push(right->left);
            }
        }
        
        return true;
    }
};