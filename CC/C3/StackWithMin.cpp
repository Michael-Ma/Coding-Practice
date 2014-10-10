#include <iostream>
#include <stack>

using namespace std;

class NodeWithMin
{
  public:
	int data;
	int min;
	NodeWithMin(){data=0; min=0;}
	NodeWithMin(int value, int m){data=value; min=m;}
};

class StackWithMin
{
  private:
	stack<NodeWithMin> source;
  public:
	void push(int value)
	{
		int min = value;
		if(!source.empty())
		{
			min = source.top().min; 
			min = value<min?value:min;
		}
		NodeWithMin tmp = NodeWithMin(value, min);
		source.push(tmp);
	}
	int min()
	{
		return source.top().min;
	}
	int pop()
	{
		int res = source.top().data;
		source.pop();
		return res;
	}
	int top()
	{
		return source.top().data;
	}
};

int main()
{
	StackWithMin test;
	test.push(3);
	test.push(2);
	test.push(33);
	test.push(1);
	test.push(0);
	cout<<"min = "<<test.min()<<endl;
	cout<<"pop = "<<test.pop()<<endl;
	cout<<"min = "<<test.min()<<endl;
	cout<<"pop = "<<test.pop()<<endl;
	cout<<"min = "<<test.min()<<endl;
	cout<<"pop = "<<test.pop()<<endl;
	cout<<"min = "<<test.min()<<endl;
	cout<<"pop = "<<test.pop()<<endl;
	cout<<"min = "<<test.min()<<endl;
	cout<<"pop = "<<test.pop()<<endl;
}

