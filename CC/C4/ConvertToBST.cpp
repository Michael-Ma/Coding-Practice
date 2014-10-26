#include <iostream>
#include <queue>
#include <string>

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

Node* convertToBST(int input[], int start, int end)
{
	if(start > end)
	{
		return NULL;
	}

	int mid = (start + end)/2;
	Node* root = new Node(input[mid]);
	root->setLeft(convertToBST(input, start, mid-1));
	root->setRight(convertToBST(input, mid+1, end));

	return root;
}

void printTree(Node* root)
{
	queue<Node*> parent;
	queue<Node*> children;
	parent.push(root);

	while(!parent.empty())
	{
		Node* cur = parent.front();
		parent.pop();
		if(cur != NULL)
		{
			cout<<cur->getValue()<<", ";
			children.push(cur->getLeft());
			children.push(cur->getRight());
		}else{
			cout<<"NULL, ";
		}

		if(parent.empty())
		{
			while(!children.empty())
			{
				parent.push(children.front());
				children.pop();
			}
			cout<<endl;
		}
	}
}

int main()
{
	int input[10] = {-1, 0, 1, 2, 3, 4, 6, 9, 12, 93};
	Node* root = convertToBST(input, 0, 9);
	printTree(root);
}
