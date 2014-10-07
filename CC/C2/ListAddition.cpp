#include <iostream>

using namespace std;

class Node
{
  public:
	int data;
	Node* next;
	Node(){data=0; next=NULL;}
	Node(int data, Node* next):data(data), next(next){}
};

Node* addList(Node* left, Node* right)
{
	Node* result = new Node;
	Node* res = result;
	bool carry = false;
	while(true)
	{
		if(left != NULL)
		{
			res->data += left->data;
			left = left->next;
		}
		if(right != NULL)
		{
			res->data += right->data;
			right = right->next;
		}
		if(carry)
		{
			res->data++;
		}

		if(res->data >= 10)
		{
			carry = true;
		}else{
			carry = false;
		}
		res->data = res->data%10;
		
		if(left!=NULL || right!=NULL || carry)
		{
			res->next = new Node;
			res = res->next;
		}else{
			break;
		}
	}

	return result;
}

int main()
{
	Node* left = new Node(5, NULL);
	left->next = new Node(1, NULL);
	left->next->next = new Node(7, NULL);
	Node* right = new Node(6, NULL);
	right->next = new Node(1, NULL);
	right->next->next = new Node(9, NULL);

	Node* result = addList(left, right);
	for(Node* r=result; r!=NULL; r=r->next)
	{
		cout<<r->data;
	}
	cout<<endl;
}

