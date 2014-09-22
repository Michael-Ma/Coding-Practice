#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;
list<int> result;

void printList(list<int> input)
{
	for(list<int>::iterator it=input.begin(); it!=input.end(); it++)
	{
		cout<<*it<<", ";
	}
	cout<<endl;
}

void printSubset(int input[], int size, int start)
{
	for(int i=start; i<size; i++)
	{
		result.push_back(input[i]);
		printList(result);
		printSubset(input, size, i+1);
		result.pop_back();
	}
}

int main()
{
	int input[7] = {1, 2, 3, 9, 0, 99, 999};
	printSubset(input, 7, 0);
}

