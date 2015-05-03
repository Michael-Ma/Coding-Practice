
/*
1.Instruction:
how to compile : g++ -g IsPalindrome.cpp -o IsPalindrome
how to run : ./IsPalindrome
2.Results:
holelost-lm:Desktop xinchenm$ ./IsPalindrome
0
1
1
*/

#include <string>
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int value=0){ val=value; next=NULL;}
};

Node* reverseList(Node* cur, Node* end){
    if(end == NULL){
        return cur;  
    }
    Node* head = reverseList(cur->next, end->next);
    end->next = cur;
    cur->next = NULL;
    return head;
}
Node* reverseList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    return reverseList(head, head->next);
}

bool isPalindrome(Node* head){
    if(head==NULL){
        return false;
    }
    //first find the middle of the list, and reverse the second part
    Node* runner = head;
    Node* walker = head;
    while(runner!=NULL && runner->next!=NULL){
        runner = runner->next->next;
        walker = walker->next;
    }
    Node* first = head;
    Node* second = walker->next;
    walker->next = NULL;
    second = reverseList(second);
    //compare the two list to see if it's palindrome
    while(first!=NULL && second!=NULL){
        if(first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

int main(){
    //1->2->3
    Node* test1 = new Node(1);
    test1->next = new Node(2);
    test1->next->next = new Node(3);
    cout<<isPalindrome(test1)<<endl;
    //1->2->3->2->1
    Node* test2 = new Node(1);
    test2->next = new Node(2);
    test2->next->next = new Node(3);
    test2->next->next->next = new Node(2);
    test2->next->next->next->next = new Node(1);
    cout<<isPalindrome(test2)<<endl;
    //1->2->3->2->3->2->1
    Node* test3 = new Node(1);
    test3->next = new Node(2);
    test3->next->next = new Node(3);
    test3->next->next->next = new Node(2);
    test3->next->next->next->next = new Node(3);
    test3->next->next->next->next->next = new Node(2);
    test3->next->next->next->next->next->next = new Node(1);
    cout<<isPalindrome(test3)<<endl;

    return 0;
}