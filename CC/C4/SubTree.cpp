#include <iostream>

using namespace std;

//used to represent binary tree
class Node
{
  protected:
	  Node* left;
	  Node* right;
	  int value;
  public:
	  Node(Node* l, Node* r, int val):left(l), right(r), value(val){}
	  Node(int val):left(NULL), right(NULL), value(val){}

	  Node* getLeft() {return left;}
	  Node* getRight() {return right;}
	  int getValue() {return value;}
	  void setLeft(Node* l) {left = l;}
	  void setRight(Node* r) {right = r;}
	  void setLeft(int val) {value = val;}
};


bool matchTree(Node* T1, Node* T2)
{
    if(T1==NULL && T2==NULL)
    {
        return true;
    }
    else if(T1==NULL || T2==NULL)
    {
        return false;
    }
    else if(T1->getValue() != T2->getValue())
    {
        return false;
    }
    else
    {
        return matchTree(T1->getLeft(), T2->getLeft()) && matchTree(T1->getRight(), T2->getRight());
    }
}

bool subTree(Node* T1, Node* T2)
{
    if(T1 == NULL)
    {
        return false;
    }
    if(T2 == NULL)
    {
        return true;  //empty tree is always a sub tree of the other tree.
    }
    if(T1->getValue() == T2->getValue())
    {
        return matchTree(T1, T2);
    }
    else
    {
        return subTree(T1->getLeft(), T2) || subTree(T1->getRight(), T2);
    }
}

int main()
{
    Node n33(-3);
    Node n32(0);
    Node n31(83);
	Node n24(&n32, &n33, 16);
	Node n23(13);
	Node n22(9);
	Node n21(&n31, NULL, 3);
	Node n12(&n23, &n24, 15);
	Node n11(&n21, &n22, 7);
	Node root(&n11, &n12, 10);

	Node nn12(13);
	Node nn11(9);
	Node root2(&nn11, &nn12, 10);
	cout<<"root and n22 is "<<subTree(&root, &n22)<<endl;
	cout<<"root and root2 is "<<subTree(&root, &root2)<<endl;


}
