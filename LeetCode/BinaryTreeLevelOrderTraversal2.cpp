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
    think about stack and queue, and try to use number to mark when/where to stop, it's memory efficient.
    Special Cases : 
    Summary: 
    
*/


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> nodeQueue;
        vector<int>      tempRes;
        int curNum  = 1;
        int nextNum = 0;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            TreeNode* tmpNode = nodeQueue.front();
            tempRes.push_back(tmpNode->val);
            nodeQueue.pop();
            curNum--;
            
            if(tmpNode->left != NULL){
                nodeQueue.push(tmpNode->left);
                nextNum++;
            }
            if(tmpNode->right != NULL){
                nodeQueue.push(tmpNode->right);
                nextNum++;
            }

            if(curNum == 0){
                result.push_back(tempRes);
                tempRes.clear();
                curNum = nextNum;
                nextNum = 0;
            }
        }
        return result;
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> nodeQueue;
        vector<int>      tempRes;
        int curNum  = 1;
        int nextNum = 0;
        int level   = 0;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            TreeNode* tmpNode = nodeQueue.front();
            tempRes.push_back(tmpNode->val);
            nodeQueue.pop();
            curNum--;
            
            if(tmpNode->left != NULL){
                nodeQueue.push(tmpNode->left);
                nextNum++;
            }
            if(tmpNode->right != NULL){
                nodeQueue.push(tmpNode->right);
                nextNum++;
            }

            if(curNum == 0){
                if(level%2 == 1){
                    for(int i=0; i<tempRes.size()/2; i++){
                        swap(tempRes[i], tempRes[tempRes.size()-i-1]);
                    }
                }
                result.push_back(tempRes);
                tempRes.clear();
                curNum = nextNum;
                nextNum = 0;
                level++;
            }
        }
        return result;
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
    vector<vector<int> > result = test.zigzagLevelOrder(root);
    for(int i=0; i<result.size(); i++){
        vector<int> tmp = result[i];
        for(int j=0; j<tmp.size(); j++){
            cout <<tmp[j]<<", ";
        }
        cout<<endl;
    }
}
