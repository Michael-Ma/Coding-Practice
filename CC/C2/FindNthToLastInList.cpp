#include <iostream>

using namespace std;

class Node
{
  public:
	string data;
	Node* next;
	Node(){data=""; next=NULL;}
	Node(string& data, Node* next):data(data), next(next){}
};

Node* findNthToLastInList(Node* head, int n)
{
	Node* p1 = head;
	Node* p2 = head;
	for(int i=0; i<n; i++, p2=p2->next)
	{
		if(p2 == NULL)
		{
			return NULL;
		}
	}
	for(; p2!=NULL; p2=p2->next, p1=p1->next){}
	return p1;
}

int main()
{
	Node head[10];
	for(int i=0; i<9; i++)
	{
		head[i].next = &head[i+1];
		head[i].data = "XXX";
	}
	head[8].data = "008";
	head[2].data = "002";
	head[5].data = "005";

	for(int i=0; i<10; i++)
	{
		cout<<head[i].data<<", ";
	}
	cout<<endl;

	cout<<"4th to last in list is :"<<findNthToLastInList(head, 4)->data<<endl;
}

