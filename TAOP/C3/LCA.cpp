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

Node* getLCA_BST(Node* node1, Node* node2, Node* root)
{
	if(node1==NULL || node2==NULL || root==NULL)
	{
		return NULL;
	}

	int val1 = node1->getValue();
	int val2 = node2->getValue();

	// make it ordered, so that it's easy to use.
	if(val1 > val2)
	{
		swap(val1, val2);
	}

	Node* cur = root;
	Node* parent = root;
	while(cur != NULL)
	{
		int val = cur->getValue();
		if(val > val2)
		{
			parent = cur;
			cur = cur->getLeft();
		}else if(val < val1){
			parent = cur;
			cur = cur->getRight();
		}else if(val==val1 || val==val2){
			return parent;
		}else{
			return cur;
		}
	}
}

Node* getLCA_BT(Node* node1, Node* node2, Node* root)
{
	if(node1==NULL || node2==NULL || root==NULL)
	{
		return NULL;
	}

	if(root==node1 || root==node2)
	{
		return root;	
	}

	Node* left  = getLCA_BT(node1, node2, root->getLeft());
	Node* right = getLCA_BT(node1, node2, root->getRight());

	if(left!=NULL && right!=NULL)
	{
		return root;
	}else if(left!=NULL){
		return left;
	}else if(right!=NULL){
		return right;
	}else{
		return NULL;
	}
}


// another algorithm for general binary tree
bool covers(Node* root, Node* p)
{
	if(root == NULL)
	{
		return false;
	}
	if(root == p)
	{
		return true;
	}
	return covers(root->getLeft(), p) || covers(root->getRight(), p);
}

Node* getCommonAncestor(Node* node1, Node* node2, Node* root)
{
	if(covers(root->getLeft(), node1) && covers(root->getLeft(), node2))
	{
		return getCommonAncestor(node1, node2, root->getLeft());
	}
	if(covers(root->getRight(), node1) && covers(root->getRight(), node2))
	{
		return getCommonAncestor(node1, node2, root->getRight());
	}
	return root;
}

int main()
{
	//case 1 is for binary search tree.
	Node n24(16);
	Node n23(13);
	Node n22(9);
	Node n21(3);
	Node n12(&n23, &n24, 15);
	Node n11(&n21, &n22, 7);
	Node root(&n11, &n12, 10);	
	cout<<"find 3 and 9 is "<<getLCA_BST(&n21, &n22, &root)->getValue()<<endl;
	cout<<"find 15 and 9 is "<<getLCA_BST(&n12, &n22, &root)->getValue()<<endl;

	//case 2 is for general binary tree.
	Node nn33(93);
	Node nn32(2);
	Node nn31(31);
	Node nn24(16);
	Node nn23(&nn32, &nn33, 13);
	Node nn22(NULL, &nn31, 9);
	Node nn21(3);
	Node nn12(&nn23, &nn24, 15);
	Node nn11(&nn21, &nn22, 7);
	Node root2(&nn11, &nn12, 10);	
	cout<<"find 31 and 9 is "<<getLCA_BT(&nn31, &nn22, &root2)->getValue()<<endl;
	cout<<"find 16 and 93 is "<<getLCA_BT(&nn24, &nn33, &root2)->getValue()<<endl;

	cout<<"find 31 and 9 is "<<getCommonAncestor(&nn31, &nn22, &root2)->getValue()<<endl;
	cout<<"find 16 and 93 is "<<getCommonAncestor(&nn24, &nn33, &root2)->getValue()<<endl;
}
