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


// Definition for binary tree with next pointer.
struct TreeNode {
     int val;
     TreeLinkNode *left, *right, *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        since need to use constant space, can't use container to save all the parents' nodes.
        but trick is since all parent nodes are connected, only save the head of parents will be good!
    Special Cases : 
    Summary: 
    
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }
        TreeLinkNode* cLevelHead = NULL;
        TreeLinkNode* pLevelHead = root;
        TreeLinkNode* cLevelCursor = NULL;
        TreeLinkNode* pLevelCursor = root;
        while(pLevelHead != NULL){
            pLevelCursor = pLevelHead;
            while(pLevelCursor != NULL){
                if(pLevelCursor->left != NULL){
                    if(cLevelHead == NULL){
                        cLevelHead = pLevelCursor->left;
                        cLevelCursor = cLevelHead;
                    }else{
                        cLevelCursor->next = pLevelCursor->left;
                        cLevelCursor = cLevelCursor->next;
                    }
                }
                if(pLevelCursor->right != NULL){
                    if(cLevelHead == NULL){
                        cLevelHead = pLevelCursor->right;
                        cLevelCursor = cLevelHead;
                    }else{
                        cLevelCursor->next = pLevelCursor->right;
                        cLevelCursor = cLevelCursor->next;
                    }
                }
                pLevelCursor = pLevelCursor->next;
            }
            pLevelHead = cLevelHead;
            cLevelHead = NULL;
        }
    }
};