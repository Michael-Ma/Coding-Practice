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



/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        careful about understanding the question, two list will merge at some point,
        and rest will be the same
    Special Cases : 
    Summary: 
    
*/ 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        
        // careful that head is not null, so it should start from 1
        int ALen = 1;
        int BLen = 1;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        while(tmpA->next != NULL){
            ALen++;
            tmpA = tmpA->next;
        }
        while(tmpB->next != NULL){
            BLen++;
            tmpB = tmpB->next;
        }
        ListNode* shortList = ALen>BLen ? headB:headA;
        ListNode* longList  = ALen>BLen ? headA:headB;
        for(int i=0; i<abs(ALen - BLen); i++){
            longList = longList->next;
        }
        for(int i=0; i<min(ALen, BLen); i++){
            if(longList == shortList){
                return shortList;
            }
            shortList = shortList->next;
            longList  = longList->next;
        }
        return NULL;
    }
};