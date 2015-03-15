#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(logn)
    Trick: using stack to maintain nodes in and out
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


class BSTIterator {
    stack<TreeNode*> smallList;
    
public:
    BSTIterator(TreeNode *root) {
        getTheLeftMostNodes(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !smallList.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = smallList.top();
        smallList.pop();
        if(node!= NULL){
            if(node->right != NULL){
                getTheLeftMostNodes(node->right);
            }
            return node->val;
        }
        return -1;
    }
    
    void getTheLeftMostNodes(TreeNode *root){
        while(root != NULL){
            smallList.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


int  main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    root->left->left->right = new TreeNode(1);

    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next()<<endl;
}