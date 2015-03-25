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


//Definition for singly-linked list with a random pointer.
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
        using a map to store the mapping from old to new, so that we can get the random in 2nd round lookup.
    Special Cases : 
    Summary: 
    
*/ 

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        RandomListNode* newHead = new RandomListNode(head->label);
        newHead->random = head->random;  //keep the old random inorder for future lookup
        RandomListNode* prev = newHead;
        RandomListNode* cur  = NULL;
        map<RandomListNode*, RandomListNode*> oldToNew;
        oldToNew[head] = newHead;
        while(head->next != NULL){
            head = head->next;
            cur = new RandomListNode(head->label);
            cur->random = head->random;
            prev->next = cur;
            oldToNew[head] = cur;
            //move to the next node
            prev = cur;
        }
        //now lookup the random part
        cur = newHead;
        while(cur != NULL){
            cur->random = oldToNew[cur->random];
            cur = cur->next;
        }
        return newHead;
    }
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        even though we want to reduce the memory useage from O(n) to O(1), we still need to keep the old -> new relationship.
        instead of using map, we need to use some existing but empty field, which may require us to change the original input.
        idea is to use new->next to connect the old->new, make it old->new->old->new->... which keep the order, and also easy to find the real random.
    Special Cases : 
    Summary: 
    
*/ 

class Solution2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        RandomListNode* newHead = new RandomListNode(head->label);
        newHead->random = head->random;  //keep the old random inorder for future lookup
        //make new node is the next of the old one, like n->o->n->o->n...
        newHead->next   = head->next;
        head->next      = newHead;
        RandomListNode* cur = newHead;
        RandomListNode* old = newHead->next;
        while(old != NULL){
            cur = new RandomListNode(old->label);
            cur->random = old->random;
            cur->next   = old->next;
            old->next  = cur;
            old = cur->next;
        }
        //now set the random correct
        cur = newHead;
        while(cur != NULL){
            if(cur->random != NULL){
                cur->random = cur->random->next;
            }
            if(cur->next != NULL){
                cur = cur->next->next;
            }else{
                break;
            }
        }
        //then split the combined list
        old = head;
        cur = newHead;
        while(cur != NULL){
            old->next = cur->next;
            //move to next
            old = old->next;
            if(old != NULL){
                cur->next = old->next;
                cur = cur->next;
            }else{
            	cur->next = NULL;
            	break;
            }
        }
        return newHead;
    }
};


int main(){
	RandomListNode* input = new RandomListNode(-1);
	Solution2 test2;
	RandomListNode* result = test2.copyRandomList(input);
	cout<<result->label<<endl;
}