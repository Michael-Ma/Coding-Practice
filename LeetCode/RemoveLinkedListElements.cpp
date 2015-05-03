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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head;
        ListNode* pre = dummyHead;
        while(cur != NULL){
            if(cur->val == val){
                pre->next = cur->next;
                cur = cur->next;  //can't move pre anymore!
            }else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummyHead->next;
    }
};