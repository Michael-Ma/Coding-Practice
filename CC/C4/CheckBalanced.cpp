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

int getMaxDepth(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + max(getMaxDepth(root->getLeft()), getMaxDepth(root->getRight()));
}

int getMinDepth(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + min(getMinDepth(root->getLeft()), getMinDepth(root->getRight()));
}

// Node: this function only checks full + balanced binary tree!
// if tree is not full, it has bug!!!
bool checkBalanced(Node* root)
{
	return (getMaxDepth(root) - getMinDepth(root) <= 1);
}


int main()
{
	//case 1 is for balanced.
	Node n24(16);
	Node n23(13);
	Node n22(9);
	Node n21(3);
	Node n12(&n23, &n24, 15);
	Node n11(&n21, &n22, 7);
	Node root(&n11, &n12, 10);	
	cout<<"Balance of tree 1 is "<<checkBalanced(&root)<<endl;

	//case 2 is for unbalanced.
	Node nn33(93);
	Node nn32(2);
	Node nn24(16);
	Node nn23(&nn32, &nn33, 13);
	Node nn12(&nn23, &nn24, 15);
	Node nn11(7);
	Node root2(&nn11, &nn12, 10);	
	cout<<"Balance of tree 2 is "<<checkBalanced(&root2)<<endl;
}
