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
#include <functional>
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

    //Merge Two Sorted Lists 
    /*
        Time Complexity  : O(m+n)
        Space Complexity : O(1)
        Trick: 
        Special Cases : 
        Summary:  
    */ 
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //init the head of the return
        ListNode* head1 = l1;
        ListNode* head2 = l2;
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






    //Merge k Sorted Lists 
    /*
        Time Complexity  : O(nklogk)
        Space Complexity : O(logk)
        Trick: 
            1. divide and conquer : divide k lists into 2 parts, and merge them, like merge sort.
            2. use heap to get the min of the heads of k lists. once pop one, push its next into heap.
        Special Cases : 
        Summary:  
    */ 
    ListNode *mergeKLists1(vector<ListNode *> &lists) {
        if(lists.size() == 0){
            return NULL;
        }
        return divideAndMerge(lists, 0, lists.size()-1);       
    }

    ListNode *divideAndMerge(vector<ListNode *> &lists, int left, int right) {
        ListNode* result = NULL;
        if(left == right){
            return lists[left];
        }
        if(left < right){
            int mid = (left+right)/2;
            ListNode* l = divideAndMerge(lists, left, mid);
            ListNode* r = divideAndMerge(lists, mid+1, right);
            result = mergeTwoLists(l, r);
        }
        return result;
    }



    /*
        Time Complexity  : O(nklogk)
        Space Complexity : O(logk)
        Trick: 
            1. divide and conquer : divide k lists into 2 parts, and merge them, like merge sort.
            2. use heap to get the min of the heads of k lists. once pop one, push its next into heap.
        Special Cases : 
        Summary:  
    */ 

    struct compareNode {
        bool operator()(const ListNode* left, const ListNode* right){
            return left->val > right->val;
        }
    };

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        if(lists.size() == 0){
            return NULL;
        }
        ListNode* result = NULL;

        // constuct priority_queue as a min heap
        priority_queue<ListNode*, vector<ListNode*>, compareNode> heap;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                heap.push(lists[i]);
            }
        }
        if(!heap.empty()){
            result = heap.top();
            heap.pop();
            if(result->next != NULL){
                heap.push(result->next);
            }
            ListNode* cur = result;
            while(!heap.empty()){
                cur->next = heap.top();
                heap.pop();
                cur = cur->next;
                //backfill the next one of what we just pop out
                if(cur->next != NULL){
                    heap.push(cur->next);
                }
            }
        }

        return result;
    }
};



int main(){
    Solution test;
    vector<ListNode *>  lists;
    ListNode * list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(2);
    ListNode * list2 = new ListNode(1);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(2);
    lists.push_back(list1);
    lists.push_back(list2);

    ListNode* sorted = test.mergeKLists2(lists);
    while(sorted != NULL){
        cout<<sorted->val<<", ";
        sorted = sorted->next;
    }
    cout<<endl;
}