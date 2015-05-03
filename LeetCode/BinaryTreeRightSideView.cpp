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
        1. using BFS, keep track of the last element of each level, using 2 vector to keep track of
        2. using DFS, make sure the right node is accessed last, and keep track of level
    Special Cases : 
    Summary: 
    
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        dfs(root, 1, result);
        return result;
    }
    void dfs(TreeNode *root, int level, vector<int> &result){
        if(root == NULL){
            return;
        }
        if(result.size() < level){
            result.resize(level);
        }
        result[level-1] = root->val;
        dfs(root->left, level+1, result);
        dfs(root->right, level+1, result);
    }
};