#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node {
  public:
   Node *left;
  Node *right;
  int value;
  Node(int val) {value = val;}
};

 int count_nodes(Node *root, int x, int y) {
    int result = 0;
    //need to check if input is valid
    if(root == NULL || x > y){
        return result;
    }
    if(root->value > y){
        result = count_nodes(root->left, x, y);
    }else if(root->value < x){
        result = count_nodes(root->right, x, y);
    }else{
        int left  = count_nodes(root->left, x, y);
        int right = count_nodes(root->right, x, y);
        result = 1 + left + right;
    }
    
    return result;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(3);
    root->left->left->right = new Node(1);

    cout<<count_nodes(root, 1, 5);

}