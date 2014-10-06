#include <iostream>
#include <map>

using namespace std;

class Node
{
  public:
	string data;
	Node* next;
	Node(){data=""; next=NULL;}
	Node(string& data, Node* next):data(data), next(next){}
};

void removeListDup(Node* head)
{
	Node* cur = head;
	Node* prev = NULL;
	map<string, bool> map;
	while(cur != NULL)
	{
		if(!map[cur->data])
		{
			map[cur->data] = true;
			prev = cur;  //remember not move prev blindly!
		}else
		{
			prev->next = cur->next;
		}
		cur = cur->next;
	}
}

void removeListDupWithoutBuffer(Node* head)
{
	Node* cmpTarget = head;
	while(cmpTarget != NULL)
	{
		Node* cur=cmpTarget->next;
		Node* prev=cmpTarget;
		for(; cur!=NULL; cur=cur->next)
		{
			if(cur->data == cmpTarget->data)
			{
				prev->next = cur->next;
			}else
			{
				prev = cur; //remember not move prev blindly!
			}
		}
		cmpTarget = cmpTarget->next;
	}
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

	Node head_dup[10];
	for(int i=0; i<9; i++)
	{
		head_dup[i].next = &head_dup[i+1];
		head_dup[i].data = head[i].data;
	}

	removeListDupWithoutBuffer(head);
	for(Node* start=head; start!=NULL; start=start->next)
	{
		cout<<start->data<<", ";
	}
	cout<<endl;

	removeListDup(head_dup);
	for(Node* start=head_dup; start!=NULL; start=start->next)
	{
		cout<<start->data<<", ";
	}
	cout<<endl;
}

