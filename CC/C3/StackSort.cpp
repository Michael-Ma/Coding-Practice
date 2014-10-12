#include <iostream>
#include <stack>

using namespace std;

void stackSort(stack<int> &input)
{
	stack<int> buffer;
	while(!input.empty())
	{
		buffer.push(input.top());
		input.pop();
	}

	while(!buffer.empty())
	{
		int cur = buffer.top();
		buffer.pop();
		while(!input.empty() && input.top()>cur)
		{
			int tmp = input.top();
			input.pop();
			buffer.push(tmp);
		}
		input.push(cur);
	}
}

int main()
{
	stack<int> test;
	test.push(8);
	test.push(0);
	test.push(-9);
	test.push(243);
	test.push(-5);
	test.push(-9);
	test.push(35);
	stackSort(test);
	while(!test.empty())
	{
		cout<<test.top()<<", ";
		test.pop();
	}
	cout<<endl;
}

