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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head->next;
        ListNode* pre = dummyHead;
        while(cur != NULL){
            pre->next->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = cur->next->next;
            if(cur!=NULL){
                cur = cur->next;
                pre = pre->next->next;
            }
        }
        return dummyHead->next;
    }
};