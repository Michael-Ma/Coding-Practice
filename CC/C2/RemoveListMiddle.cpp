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

//can't remove the last one for singe linked list.
void removeListMiddle(Node* mid)
{
	if(mid==NULL || mid->next==NULL)
	{
		return;
	}
	mid->data = mid->next->data;
	mid->next = mid->next->next;	
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

	cout<<"After remove the middle, the list is:"<<endl;
	removeListMiddle(&head[5]);
	for(Node* start=head; start!=NULL; start=start->next)
	{
		cout<<start->data<<", ";
	}
	cout<<endl;
}

