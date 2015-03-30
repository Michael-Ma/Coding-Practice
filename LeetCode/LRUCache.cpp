#include <sstream>
#include <stdio.h>
#include <climits>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


/*
    Time Complexity  : O(1)
    Space Complexity : O(1)
    Trick: major is about corner cases.. like if it's head, and if it's tail, sth like that.
    Special Cases : 
    Summary: 
    
*/ 

class LRUCache{
public:
    struct Node{
        int   key;
        int   value;
        Node* prev;
        Node* next;

        Node(int key=0, int value=0, Node* prev=NULL, Node* next=NULL){
            this->key   = key;
            this->value = value;
            this->prev  = prev;
            this->next  = next;
        }
    };
    
    int capacity;
    int size;
    map<int, Node*> Map;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        Node* res = NULL;
        res = Map[key];
        //return -1 if key doesn't exsit
        if(res == NULL){
            return -1;
        }else{
            moveToHead(res);
        }
        return res->value;
    }
    
    void set(int key, int value) {
        Node* res = Map[key];
        if(res == NULL){
            //add new node
            Node* newNode = new Node(key, value);
            Map[key] = newNode;
                        
            if(size >= capacity){
                removeTail();
            }

            if(head==NULL && size==0){
                head = newNode;
                tail = newNode;
            }else{
                //move to head
                moveToHead(newNode);
            }
            size++;

        }else{
            //set new value
            res->value = value;
            //move to head
            moveToHead(res);
        }
    }
    
    void moveToHead(Node* node){
        if(head == NULL){
            head = node;
            return;
        }
        if(node==NULL || node==head){
            return;
        }
        if(node == tail){
            tail = tail->prev;
        }
        //move it out of the chain, if it's in the chain
        if(node->prev != NULL){
            node->prev->next = node->next;
            if(node->next != NULL){
                node->next->prev = node->prev;
            }
        }
        //move to the head
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }
    
    void removeTail(){
        if(tail == NULL){
            return;
        }
        if(tail->prev == NULL){
            head = NULL;
        }else{
            tail->prev->next = NULL;
        }
        Map[tail->key] = NULL;
        Node* tmp = tail;
        tail = tail->prev;
        delete tmp;
        size--;
    }
    
    void moveToTail(Node* node){
        if(tail == NULL){
            tail = node;
            return;
        }
        if(node==NULL || node==tail){
            return;
        }
        //move it out of the chain, if it's in the chain
        if(node->prev != NULL){
            node->prev->next = node->next;
            if(node->next != NULL){
                node->next->prev = node->prev;
            }
        }
        //move to the tail
        node->next = NULL;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
};

int main(){
    LRUCache cache(2);
    cache.set(2,1);
    cache.get(2);
    cache.set(3,2);
    cache.get(2);
    cache.get(3);
    return 0;
}