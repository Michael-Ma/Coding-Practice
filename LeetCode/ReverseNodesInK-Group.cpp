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
        using dummy head is pretty neat!
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<=1){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head;
        ListNode* pre = dummyHead;
        int counter = 1;
        while(cur!=NULL && counter<=k){
//        	cout<<cur->val<<", "<<counter<<endl;
            if(counter == k){
                counter = 0;
                // cur must be updated before passing to reverseList, otherwise cur will be messed up.
                cur = cur->next;
                pre = reverseList(pre, cur);
            }else{
            	cur = cur->next;
        	}
            counter++;
        }
        return dummyHead->next;
    }
    
    ListNode* reverseList(ListNode* dummyHead, ListNode* end){
        if(dummyHead==NULL || dummyHead->next==NULL){
            return NULL;
        }
        ListNode* head = dummyHead->next;
        ListNode* cur = dummyHead->next->next;
        //reverse linked list is simply change the link from tail to head
        //use dummyHead to keep track of the head of reversed part
        while(cur != end){
            ListNode* tmp = cur->next;
            cur->next = dummyHead->next;
            dummyHead->next = cur;
            cur = tmp;
        }
        head->next = end;
        return head;
    }
};

int main(){
	Solution test;
	ListNode* input = new ListNode(1);
	input->next = new ListNode(2);
	input->next->next = new ListNode(3);
	input->next->next->next = new ListNode(4);
	ListNode* result = test.reverseKGroup(input, 3);
	while(result!=NULL){
		cout<<result->val<<", ";
		result = result->next;
	}
	cout<<endl;
}