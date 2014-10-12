#include <iostream>
#include <vector>

using namespace std;

class Node
{
  public:
	int data;
	Node* next;
	Node(){data=0; next=NULL;}
	Node(int data, Node* next):data(data), next(next){}
};

class Stack
{
  private:
	int capacity;
	int size;
	Node* top;
	Node* bottom;

  public:
	Stack(int cap):capacity(cap), size(0), top(NULL), bottom(NULL){}
	void push(Node* node);
	Node* pop();
	Node* popBottom();
	bool isEmpty() {return size==0;}
	bool isFull() {return size==capacity;}
};

void Stack::push(Node* node)
{
	if(top==NULL || bottom==NULL)
	{
		top = node;
		bottom = node;
		size++;
	}else if(size < capacity){
		node->next = top;
		top = node;
		size++;
	}
}

Node* Stack::pop()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node* result = top;
	top = top->next;
	size--;
	return result;
}

Node* Stack::popBottom()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node* result = bottom;
	bottom = bottom->next;
	size--;
	return result;
}

// a set of stacks with same capacity
class StackSet
{
  private:
	vector<Stack> stackSet;
	int stackCap;    //capacity for each stack

  public:
	StackSet(int cap):stackCap(cap){}
	void push(Node* node);
	Node* pop();
	Node* popAt(int index);
};

void StackSet::push(Node* node)
{
	int curIndex = stackSet.size()-1;
	if(curIndex<0 || stackSet[curIndex].isFull())
	{
		Stack newStack(stackCap);
		newStack.push(node);
		stackSet.push_back(newStack);
	}else{
		stackSet[curIndex].push(node);
	}
}

Node* StackSet::pop()
{
	int curIndex = stackSet.size()-1;
	Node* result = stackSet[curIndex].pop();
	if(stackSet[curIndex].isEmpty())
	{
		stackSet.pop_back();
	}
	return result;
}

Node* StackSet::popAt(int index)
{
	int curIndex = stackSet.size()-1;
	if(index > curIndex)
	{
		return NULL;
	}

	Node* result = stackSet[index].pop();
	for(int i=index+1; i<=curIndex; i++)
	{
		Node* bottom = stackSet[i].popBottom();
		stackSet[i-1].push(bottom);
	}
	if(stackSet[curIndex].isEmpty())
	{
		stackSet.pop_back();
	}
	return result;
}



int main()
{
	Node* n1 = new Node(1, NULL);
	Node* n2 = new Node(2, NULL);
	Node* n3 = new Node(3, NULL);
	Node* n4 = new Node(4, NULL);
	Node* n5 = new Node(5, NULL);
	StackSet set(3);
	set.push(n1);
	set.push(n2);
	set.push(n3);
	set.push(n4);
	set.push(n5);
	cout<<"set.popAt(0) = "<<set.popAt(0)->data<<endl;
	cout<<"set.pop() = "<<set.pop()->data<<endl;
}

