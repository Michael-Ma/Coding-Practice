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



class Solution {
public:
/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        trick is to remove the compared part from sum to make it able to be called again.
    Special Cases : 
    Summary: 
        tree will usually use recursion!
*/ 
    // Path Sum
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL){
            return false;
        }
        //identify if it's leaf
        if(root->left==NULL && root->right==NULL && root->val==sum){
            return true;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }




/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        Basically it's binary search!
    Special Cases : 
    Summary: 
    
*/ 
    // Path Sum II
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > results;
        if(root == NULL){
            return results;
        }
        
        vector<int> result;
        findSumPath(root, sum, result, results);
        return results;
    }
    
    void findSumPath(TreeNode *root, int sum, vector<int> result, vector<vector<int> > &results){
        if(root == NULL){
            return;
        }
        result.push_back(root->val);
        //identify if it's leaf
        if(root->left==NULL && root->right==NULL && root->val==sum){
            results.push_back(result);
        }else{
            findSumPath(root->left, sum-root->val, result, results);
            findSumPath(root->right, sum-root->val, result, results);
        }
    }
};