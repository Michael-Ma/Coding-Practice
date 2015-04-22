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
        the hard part is the boundary situation.
*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL || head->next==NULL || m>=n){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head;
        ListNode* pre = dummyHead;
        int counter = 1;
        while(counter<m && cur!= NULL){
            cur = cur->next;
            pre = pre->next;
            counter++;
        }
        ListNode* tail = cur;
        ListNode* tail_pre = pre;
        cur = cur->next;
        pre = pre->next;
        counter++;
        while(counter<=n && cur!=NULL){
            ListNode* tmpNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmpNext;
            counter++;
        }
        //now pre is the nth element, cur is the nth element.
        tail_pre->next = pre;
        tail->next = cur;
        
        return dummyHead->next;
    }
};