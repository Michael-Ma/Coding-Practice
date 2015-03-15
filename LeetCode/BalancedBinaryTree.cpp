#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: recursively get the depth of the tree, return -1 if early found unbalance
    Special Cases : 
    Summary: 
*/



// Definition for binary tree*
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return isBalancedHelper(root)>=0;
    }

    int isBalancedHelper(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int left = isBalancedHelper(root->left);
        int right = isBalancedHelper(root->right);
        if(left<0 || right<0 || abs(left-right)>=2){
            return -1;
        }
        return max(left, right)+1;
    }
};

int  main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    Solution test;
    cout<<test.isBalanced(root)<<endl;

    return 0;
}