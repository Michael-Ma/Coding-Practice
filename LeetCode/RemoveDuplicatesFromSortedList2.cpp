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

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        
    Special Cases : 
    Summary: 
*/
// Remove Duplicates from Sorted List
class Solution1 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* cur = head->next;
        ListNode* pre = head;
        while(cur != NULL){
            if(cur->val != pre->val){
                pre = pre->next;
            }else{
                //remove the dup
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return head;
    }
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        
    Special Cases : 
    	need to think about the tail conditions, if it exits but there may still be some cleaning works to do!
    Summary: 
*/
// Remove Duplicates from Sorted List II 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head->next;
        ListNode* pre = dummyHead;
        bool isDup = false;
        while(cur != NULL){
            if(cur->val == pre->next->val){
                isDup = true;
            }else{
                //need to remove dup when encounter the first non dup
                if(isDup){
                    pre->next = cur;
                    isDup = false;
                }else{
                    pre = pre->next;
                }
            }
            cur = cur->next;
        }
        //if all the tails are the same, need to remove them
        if(isDup){
            pre->next = cur;
        }
        return dummyHead->next;
    }
};