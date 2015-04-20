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


/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
    Special Cases : 
        careful about the case when fur == cur->next!!
    Summary: 
        try to add a dummy head in front of the whole list in order to save some effort!
*/

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* result = NULL;
        if(head == NULL){
            return result;
        }
        ListNode* cur = head;  //current last element < x
        ListNode* prev = NULL; //prvious node for fur
        ListNode* fur = NULL;  //furture node
        //settle the first element for return purpose
        if(cur->val < x){
            result = cur;
            prev = cur;
            fur = cur->next;
        }else{
            while(cur->next!=NULL && cur->next->val>=x){
                cur = cur->next;
            }
            if(cur->next == NULL){
                return head;
            }else{
                result = cur->next;
                ListNode* tmp = cur->next->next;
                cur->next->next = head;
                cur->next = tmp;
                prev = cur;
                fur = cur->next;
                cur = result;
            }
        }
        //for the rest nodes
        while(fur != NULL){
            if(fur->val < x && fur != cur->next){
                ListNode* tmp_c = cur->next;
                ListNode* tmp_f = fur->next;
                cur->next = fur;
                cur = cur->next;
                cur->next = tmp_c;
                prev->next = tmp_f;
                fur = tmp_f;
            }else if(fur->val < x){
                cur = cur->next;
                fur = fur->next;
                prev = prev->next;
            }else{
                prev = fur;
                fur = fur->next;
            }
        }
        
        return result;
    }
};

int main(){
    Solution test;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    ListNode* result = test.partition(head, 2);
    while(result!=NULL){
        cout<<result->val<<", ";
        result = result->next;
    }
    cout<<endl;
}