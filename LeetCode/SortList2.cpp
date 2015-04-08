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


// Definition for list
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



class Solution {
public:
    // Sort List
    //using merge sort
    /*
        Time Complexity  : O(nlogn)
        Space Complexity : O(logn)
        Trick: 
        
        Special Cases : 
            care about when should it split, and when should it return.
            if the list can't be divided any more, then it should return, i.e. head==NULL || head->next==NULL
        Summary: 
        
    */ 
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *mid  = head;
        ListNode *tail = head;
        while(tail->next!=NULL && tail->next->next!=NULL){
            mid  = mid->next;
            tail = tail->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = mid->next;
        mid->next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
    
    ListNode* merge(ListNode *head1, ListNode *head2){
        //init the head of the return
        ListNode* result = NULL;
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        if(head1->val > head2->val){
            result = head2;
            head2  = head2->next;
        }else{
            result = head1;
            head1  = head1->next;
        }
        ListNode* prev = result;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                prev->next = head1;
                head1 = head1->next;
                prev = prev->next;
                prev->next = NULL;
            }else{
                prev->next = head2;
                head2 = head2->next;
                prev = prev->next;
                prev->next = NULL;
            }
        }
        if(head1 != NULL){
            prev->next = head1;
        }else if(head2 != NULL){
            prev->next = head2;
        }
        return result;
    }





    // Insertion Sort List 
    /*
        Time Complexity  : O(n^2)
        Space Complexity : O(1)
        Trick: 
        
        Special Cases : 
        Summary: 
        
    */ 
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = dummyHead;
        while(cur != NULL){
            ListNode* next = cur->next;
            pre = dummyHead;
            while(pre->next!=NULL && pre->next->val <= cur->val){
                pre = pre->next;
            }

            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummyHead->next;
    }
};


int main(){
    Solution test;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    ListNode* sorted = test.insertionSortList(head);
    while(sorted != NULL){
        cout<<sorted->val<<", ";
        sorted = sorted->next;
    }
    cout<<endl;
}