#include <iostream>

using namespace std;

//used to represent binary tree.
//This version is doubly linked.
class Node
{
  protected:
      Node* left;
      Node* right;
      Node* parent;
      int value;
  public:
      Node(Node* l, Node* r, Node* p, int val):left(l), right(r), parent(p), value(val){}
      Node(int val):left(NULL), right(NULL), parent(NULL), value(val){}

      Node* getLeft() {return left;}
      Node* getRight() {return right;}
      Node* getParent() {return parent;}
      int getValue() {return value;}
      void setLeft(Node* l) {left = l;}
      void setRight(Node* r) {right = r;}
      void setParent(Node* p) {parent = p;}
      void setLeft(int val) {value = val;}
};


//find first parent which is on the right of node
Node* findNextInParent(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }

    Node* parent = node->getParent();
    while(parent != NULL)
    {
        if(parent->getLeft() == node)
        {
            break;
        }else{
            node = parent;
            parent = parent->getParent();
        }
    }
    return parent;
}

//find the most left child of node's right child.
Node* findNextInChild(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }

    Node* right = node->getRight();
    if(right == NULL)
    {
        return NULL;
    }

    Node* left = right->getLeft();
    while(left != NULL)
    {
        if(left->getLeft() != NULL)
        {
            left = left->getLeft();
        }else{
            break;
        }
    }

    //if right child doesn't have left children, return right.
    if(left == NULL)
    {
        return right;
    }

    return left;
}

Node* findNextInBST(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }

    Node* result = findNextInChild(node);
    if(result == NULL)
    {
        result = findNextInParent(node);
    }

    return result;
}


int main()
{
	Node n24(16);
	Node n23(13);
	Node n22(9);
	Node n21(3);
	Node n12(&n23, &n24, NULL, 15);
	Node n11(&n21, &n22, NULL, 7);
	Node root(&n11, &n12, NULL, 10);
    n11.setParent(&root);
    n12.setParent(&root);
    n21.setParent(&n11);
    n22.setParent(&n11);
    n23.setParent(&n12);
    n24.setParent(&n12);

    Node* tmp = &n22;
    while(tmp != NULL)
    {
        cout<<tmp->getValue()<<", ";
        tmp = findNextInBST(tmp);
    }
    cout<<endl;
}

