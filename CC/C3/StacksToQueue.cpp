#include <iostream>
#include <stack>

using namespace std;

template<class T> 
class MyQueue
{
  private:
	stack<T*> head;
	stack<T*> tail;
  public:
	void inqueue(T* data);
	T* dequeue();
	T* top();
	int size(){return head.size()+tail.size();}
};

template<class T> 
void MyQueue<T>::inqueue(T* data)
{
	head.push(data);
}

template<class T> 
T* MyQueue<T>::dequeue()
{
	if(size() == 0)
	{
		return NULL;
	}

	if(tail.empty())
	{
		while(!head.empty())
		{
			T* temp = head.top();
			tail.push(temp);
			head.pop();
		}
	}
	T* res = tail.top();
	tail.pop();
	return res;
}

template<class T> 
T* MyQueue<T>::top()
{
	if(size() == 0)
	{
		return NULL;
	}

	if(tail.empty())
	{
		while(!head.empty())
		{
			T* temp = head.top();
			tail.push(temp);
			head.pop();
		}
	}
	T* res = tail.top();
	return res;
}

int main()
{
	MyQueue<string> queue;
	string input1 = "001";
	string input2 = "002";
	string input3 = "003";
	string input4 = "004";
	string input5 = "005";
	string input6 = "006";
	queue.inqueue(&input1);
	queue.inqueue(&input2);
	queue.inqueue(&input3);
	queue.inqueue(&input4);
	queue.inqueue(&input5);
	queue.inqueue(&input6);
	cout<<"top is "<<*queue.top()<<endl;
	for(int i=queue.size(); i>0; i--)
	{
		cout<<"dequeue is "<<*queue.dequeue()<<endl;
	}
}

