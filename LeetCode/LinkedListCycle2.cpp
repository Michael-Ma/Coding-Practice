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
        1. hashmap
        2. fast runner & slow runner
    Special Cases : 
    Summary: 
    
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        do{
            if(fast==NULL || fast->next==NULL){
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        
        ListNode* cycleBegin = head;
        while(cycleBegin != slow){
            cycleBegin = cycleBegin->next;
            slow = slow->next;
        }
        return cycleBegin;
    }
};