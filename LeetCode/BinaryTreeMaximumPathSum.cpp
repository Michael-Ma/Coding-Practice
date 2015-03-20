#include <sstream>
#include <stdio.h>
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
    sum = (left, 0) + node + (right, 0)
    every node may be the node with max sum, 
    so it's more efficient to return the max during the calculation for each node.
    Special Cases : 
    Summary: 
    
*/


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int maxSum = root->val;
        getMaxSubTree(root, maxSum);
        return maxSum;
    }
    
    int getMaxSubTree(TreeNode* root, int& maxSum){
        if(root == NULL){
            return 0;
        }
        int left  = getMaxSubTree(root->left, maxSum);
        int right = getMaxSubTree(root->right, maxSum);
        int curSum = root->val + max(left, 0) + max(right, 0);
        if(curSum > maxSum){
            maxSum = curSum;
        }
        return root->val + max(left, max(right, 0));
    }
};



int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    root->left->left->right = new TreeNode(1);

    Solution test;
    cout<<test.maxPathSum(root)<<endl;
}
