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
        care about when step==0!
    Summary: 
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //get the length of the list
        ListNode* tmpHead = head;
        int length = 0;
        while(tmpHead != NULL){
            tmpHead = tmpHead->next;
            length++;
        }
        //update k, then consider when k==0
        k = k%length;
        if(k <= 0){
            return head;
        }
        //find the new head pos
        ListNode* newHead = head;
        ListNode* first   = head;
        ListNode* second  = head;
        while(k>0){
            second = second->next;
            k--;
        }
        while(second->next != NULL){
            first  = first->next;
            second = second->next;
        }
        //rotate the list
        newHead = first->next;
        first->next = NULL;
        second->next = head;
        return newHead;
    }
};