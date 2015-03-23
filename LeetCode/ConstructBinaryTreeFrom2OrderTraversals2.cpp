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
        recursively solve tree problem!
        1. use map to fast access root index!
        2. key poin is to find the right start and end of left subtree and right subtree, after getting root
        3. 2 relation can be used: 
        	1)root split the left and right in inorder; 
        	2)length of left subtree is same in both inorder and postorder;
    Special Cases : 
    Summary: 
    
*/

class InorderPostorderBuild {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0 || postorder.size()==0){
            return NULL;
        }
        map<int, int> inPosMap;
        for(int i=0; i<inorder.size(); i++){
            inPosMap[inorder[i]] = i;
        }
        return parseAndReturnRoot(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inPosMap);
    }
    
    TreeNode *parseAndReturnRoot(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int po_start, int po_end, map<int, int> &inPosMap){
        if(in_start>in_end || po_start>po_end){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[po_end]);
        int rootIndex = inPosMap[postorder[po_end]];  //pos for root in inorder
        root->left = parseAndReturnRoot(inorder, in_start, rootIndex-1, postorder, po_start, po_start+rootIndex-in_start-1, inPosMap);
        root->right = parseAndReturnRoot(inorder, rootIndex+1, in_end, postorder, po_start+rootIndex-in_start, po_end-1, inPosMap);
        return root;
    }
};



class InorderPreorderBuild {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(inorder.size()==0 || preorder.size()==0){
            return NULL;
        }
        map<int, int> inPosMap;
        for(int i=0; i<inorder.size(); i++){
            inPosMap[inorder[i]] = i;
        }
        return parseAndReturnRoot(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, inPosMap);
    }
    
    TreeNode *parseAndReturnRoot(vector<int> &inorder, int in_start, int in_end, vector<int> &preorder, int pr_start, int pr_end, map<int, int> &inPosMap){
        if(in_start>in_end || pr_start>pr_end){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pr_start]);
        int rootIndex = inPosMap[preorder[pr_start]];  //pos for root in inorder
        root->left = parseAndReturnRoot(inorder, in_start, rootIndex-1, preorder, pr_start+1, pr_start+rootIndex-in_start, inPosMap);
        root->right = parseAndReturnRoot(inorder, rootIndex+1, in_end, preorder, pr_start+rootIndex-in_start+1, pr_end, inPosMap);
        return root;
    }
};