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

Node* findCycleStart(Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}

	Node* p1 = head;
	Node* p2 = head;
	//first find the mid point of the List
	while(p2!=NULL && p2->next!=NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1 == p2)
		{
			break;	
		}
	}
	// in case it's not cycle linked
	if(p2==NULL || p2->next==NULL)
	{
		return NULL;
	}

	//second let fast one start from mid point, while the other start from beginning.
	p1 = head;
	while(p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

int main()
{
	Node head[10];
	for(int i=0; i<9; i++)
	{
		head[i].next = &head[i+1];
		head[i].data = "XXX";
	}
	head[9].data = "end";
	head[2].data = "start";
	head[9].next = &head[2];
	for(int i=0; i<10; i++)
	{
		cout<<head[i].data<<", ";
	}
	cout<<endl;

	Node* res = findCycleStart(head);
	cout<<"start of cycle is : "<<res->data<<endl;
}

