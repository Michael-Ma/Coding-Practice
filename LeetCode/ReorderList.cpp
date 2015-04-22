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
        need to write how to reverse the linked list really fast
*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        //first find the middle of the list
        ListNode* runner = head;
        ListNode* walker = head;
        while(runner!=NULL && runner->next!=NULL){
            runner = runner->next->next;
            walker = walker->next;
        }
        //reverse the second part, and then merge them together
        ListNode* first = head;
        ListNode* second = walker->next;
        walker->next = NULL;
        second = reverseList(second);
        while(first!=NULL && second!=NULL){
            ListNode* tmp = first->next;
            first->next = second;
            second = second->next;
            first = first->next;
            first->next = tmp;
            first = tmp;
        }
    }
    
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        return reverseList(head, head->next);
    }
    ListNode* reverseList(ListNode* cur, ListNode* end){
        if(end == NULL){
            return cur;  //trick! the last recursion will always return the new head
        }
        ListNode* head = reverseList(cur->next, end->next);
        end->next = cur;
        cur->next = NULL;
        return head;
    }
};

int main(){
    Solution test;
}