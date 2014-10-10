#include <iostream>

using namespace std;

const int N = 300;

//using an array to represent 3 stacks.
class Stack
{
  private:
	int array[N*3];
	int curHead[3];   //pointer to the current head for each stack

  public:
	Stack()
	{
		for(int i=0; i<3; i++)
		{
			curHead[i] = 0;
		}
	}
	
	int peek(int stackNum);
	int pop(int stackNum);
	void push(int stackNum, int value);
};

int Stack::peek(int stackNum)
{
	return array[stackNum*N + curHead[stackNum]];
}

int Stack::pop(int stackNum)
{
	int result = 0;
	if(curHead[stackNum] > 0){
		result = array[stackNum*N + curHead[stackNum]];
		array[stackNum*N + curHead[stackNum]] = 0;
		curHead[stackNum]--;
	}
	return result;
}

void Stack::push(int stackNum, int value)
{
	if(curHead[stackNum] < N){
		curHead[stackNum]++;
		array[stackNum*N + curHead[stackNum]] = value;
	}
}

int main()
{
	Stack test;
	test.push(0, 23);
	test.push(0, 2);
	test.push(0, 3);
	test.push(1, 30);
	test.push(1, 11);
	test.push(2, 2);
	cout<<"stack 0 peek():"<<test.peek(0)<<endl;
	cout<<"stack 0 pop():"<<test.pop(0)<<endl;
	cout<<"stack 0 pop():"<<test.pop(0)<<endl;
	cout<<"stack 1 peek():"<<test.peek(1)<<endl;
	cout<<"stack 1 pop():"<<test.pop(1)<<endl;
	cout<<"stack 2 peek():"<<test.peek(2)<<endl;
	cout<<"stack 2 pop():"<<test.pop(2)<<endl;
}

