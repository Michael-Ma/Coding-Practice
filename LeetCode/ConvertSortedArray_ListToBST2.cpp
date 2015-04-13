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
#include <cfloat> 
#include <climits> 
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
        Basically it's binary search!
    Special Cases : 
    Summary: 
    
*/ 

class ArrayToBST {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0){
            return NULL;
        }
        return getSubtreeRoot(num, 0, num.size()-1);
    }
    
    TreeNode *getSubtreeRoot(vector<int> &num, int start, int end){
        if(start>end || start<0 || end>=num.size()){
            return NULL;
        }
        int pos = (start+end)/2;
        TreeNode* root = new TreeNode(num[pos]);
        root->left  = getSubtreeRoot(num, start, pos-1);
        root->right = getSubtreeRoot(num, pos+1, end);
        return root;
    }
};




//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        using inorder traversal to build the tree
    Special Cases : 
        need to understand how it works! actually wen it get returned after calculating left, the node we are talking about is also changed.
    Summary: 
    
*/ 
class ListToBST {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        int size = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            size++;
        }
        return getRootByInorderTraverse(head, 0, size-1);
    }
    
    TreeNode* getRootByInorderTraverse(ListNode* &head, int start, int end){
        if(head==NULL || start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* left  = getRootByInorderTraverse(head, start, mid-1);
        TreeNode* root  = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = getRootByInorderTraverse(head, mid+1, end);
        root->left  = left;
        root->right = right;
        return root;
    }
};