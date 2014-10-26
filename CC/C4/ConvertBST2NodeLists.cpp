#include <iostream>
#include <vector>
#include <list>
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

vector<list<Node*> >* convertBST2NodeLists(Node* root)
{
	vector<list<Node*> >* result = new vector<list<Node*> >;
	list<Node*> parent;
	list<Node*> children;
	
	parent.push_back(root);
	result->push_back(parent);
	while(!parent.empty())
	{
		Node* cur = parent.front();
		parent.pop_front();
		if(cur->getLeft() != NULL)
		{
			children.push_back(cur->getLeft());
		}
		if(cur->getRight() != NULL)
		{
			children.push_back(cur->getRight());
		}
		if(parent.empty())
		{
			if(!children.empty())
			{
				parent.swap(children);	
				result->push_back(parent);
			}
		}
	}
	return result;
}

int main()
{
	Node n24(16);
	Node n23(13);
	Node n22(9);
	Node n21(3);
	Node n12(&n23, &n24, 15);
	Node n11(&n21, &n22, 7);
	Node root(&n11, &n12, 10);	

	vector<list<Node*> >* result = convertBST2NodeLists(&root);
	for(int i=0; i<result->size(); i++)
	{
		list<Node*> tmp = result->at(i);
		for(list<Node*>::iterator it=tmp.begin(); it!=tmp.end(); it++)
		{
			cout<<(*it)->getValue()<<", ";
		}
		cout<<endl;
	}

}
