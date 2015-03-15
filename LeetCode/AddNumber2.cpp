#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


 /*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    Special Cases : need to know that the carry may cause adding another number!
    Summary: 
*/
class AddTwoNumbersSolution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode* res = NULL;
    	ListNode* cur = NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
        	int result = l1->val + l2->val + carry;
        	carry = result/10;
        	result = result%10;
        	if(res == NULL){
        		res = new ListNode(result);
        		cur = res;
        	}else{
        		cur->next = new ListNode(result);
        		cur = cur->next;
        	}
        	l1 = l1->next;
        	l2 = l2->next;
        }
        while(l1!=NULL){
        	int result = l1->val + carry;
        	carry = result/10;
        	result = result%10;
        	if(res == NULL){
        		res = new ListNode(result);
        		cur = res;
        	}else{
        		cur->next = new ListNode(result);
        		cur = cur->next;
        	}
        	l1 = l1->next;
        }
        while(l2!=NULL){
        	int result = l2->val + carry;
        	carry = result/10;
        	result = result%10;
        	if(res == NULL){
        		res = new ListNode(result);
        		cur = res;
        	}else{
        		cur->next = new ListNode(result);
        		cur = cur->next;
        	}
        	l2 = l2->next;
        }

        //corner case!
        if(carry > 0){
        	cur->next = new ListNode(carry);
        }

        return res;
    }
};



 /*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    Special Cases : need to know that the carry may cause adding another number!
    				it actually starts from the end of the string, and result should be added to the head!
    Summary: 
*/
class AddBinarySolution {
public:
    string addBinary(string a, string b) {
        if(a.length() == 0){
        	return b;
        }
        if(b.length() == 0){
        	return a;
        }
        int aCur = a.length()-1;
        int bCur = b.length()-1;
        int carry = 0;
        int result_num = 0;
        string result_str = "";
        while(aCur>=0 && bCur>=0){
        	result_num = (a[aCur]-'0') + (b[bCur]-'0') + carry;
        	carry  = result_num/2;
        	result_num = result_num%2;
        	result_str= (char)(result_num+(int)'0')+result_str;
        	aCur--;
        	bCur--;
        }
        while(aCur>=0){
        	result_num = (a[aCur]-'0') + carry;
        	carry  = result_num/2;
        	result_num = result_num%2;
        	result_str = (char)(result_num+(int)'0')+result_str;
        	aCur--;
        }
        while(bCur>=0){
        	result_num = (b[bCur]-'0') + carry;
        	carry  = result_num/2;
        	result_num = result_num%2;
        	result_str = (char)(result_num+(int)'0')+result_str;
        	bCur--;
        }
        //corner case!
        if(carry > 0){
        	result_str = (char)(carry+(int)'0')+result_str;
        }

        return result_str;
    }
};



int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	AddTwoNumbersSolution solution1;
	ListNode* res = solution1.addTwoNumbers(l1, l2);
	cout<<"result1 is : "<<res->val<<" -> "<<res->next->val<<" -> "<<res->next->next->val<<endl;

	AddBinarySolution solution2;
	string input1 = "111";
	string input2 = "11";
	cout<<"result2 is : "<<solution2.addBinary(input1, input2)<<endl;

	return 0;
}
