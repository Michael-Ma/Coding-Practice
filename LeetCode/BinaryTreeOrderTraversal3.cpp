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


// Definition for binary tree*
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    Time Complexity  : O(n)
    Space Complexity : O(logn) - O(1)
    Trick: 
    Special Cases : 
    Summary: 
    for this kind of problems, using stack is for storing info which will be needed in the future,
    when the program is running back to this point.
*/

class Solution {
public:
	//recursive
    vector<int> preorderTraversal_re(TreeNode *root) {
        vector<int> result;
        preRecursive(root, result);
        return result;
    }
    void preRecursive(TreeNode *root, vector<int> &result){
    	if(root == NULL){
    		return;
    	}
    	result.push_back(root->val);
    	preRecursive(root->left, result);
    	preRecursive(root->right, result);
    }

	//iterative
    vector<int> preorderTraversal_it1(TreeNode *root) {  //memory usage is too much!!
    	vector<int> result;
        stack<TreeNode*> pending;
        while(root != NULL){
        	if(root->left != NULL){
        		pending.push(root->left);
        	}
        	if(root->right != NULL){
        		pending.push(root->right);
        	}
        	result.push_back(root->val);
        	if(!pending.empty()){
        		root = pending.top();
        		pending.pop();
        	}
        }
        return result;
    }

    vector<int> preorderTraversal_it2(TreeNode *root) {
    	vector<int> result;
        stack<TreeNode*> pending;
        while(root!=NULL || !pending.empty()){
        	if(root != NULL){
        		result.push_back(root->val);
        		pending.push(root->right);
        		root = root->left;
        	}else{
        		root = pending.top();
        		pending.pop();
        	}
        }
        return result;
    }


    //Morris
    //using all the empty right node to point back to the upper level node that you loss connect
    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> result;
    	TreeNode* 	cur = root;
    	TreeNode*	pre = NULL;
        
        while(cur != NULL){
        	if(cur->left == NULL){
        		result.push_back(cur->val);
        		cur = cur->right;
        	}else{
        		pre = cur->left;
        		//find the rightest node and point back to its next, which is the current
        		while(pre->right!=NULL && pre->right!=cur){  //node that the rightest node will be accessed twice.
        			pre = pre->right;
        		}
        		if(pre->right == NULL){  //if it's the first time access, set a way back to upper level
         			pre->right = cur;
         			cur = cur->left;  //move on after set it up
        		}else{   // if it's the second time, revoke what you have done before
        			pre->right = NULL;
        			result.push_back(cur->val);  // add cur because all the node on the left has finished
        			cur = cur->right;  //move to the other side then.
        		}
        	}
        }
        return result;
    }

    //iterative
    //this one is a little tricky!!
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> pending;
        TreeNode* pre = NULL;

        while(root != NULL || !pending.empty()){
        	if(root!=NULL){
        		pending.push(root);
        		root = root->left;
        	}else{
        		TreeNode* peek = pending.top();
        		if(peek->right == NULL || peek->right==pre){
        			result.push_back(peek->val);
        			pre = peek;		
        			pending.pop();
        		}else{
        			root = peek->right;
        		}
        	}
        }

        return result;
    }
};