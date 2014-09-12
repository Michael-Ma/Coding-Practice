#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * print out all the possibile combination of char in existing string.
 * abc -> acb bac bca cab cba
 */
void printAllPermutation(char* input, int from, int to)
{
	if(input==NULL || to<=1 || from > to)
	{
		return;
	}

	if(from == to)
	{
		for(int i=0; i<=to; i++)
		{
			cout<<input[i];
		}
		cout<<" : ";
	}

	if(from < to)
	{
		for(int j=from; j<=to; j++)
		{
			swap(input[j], input[from]);
			printAllPermutation(input, from+1, to);
			swap(input[j], input[from]);   //need to restore back to the origin string, or you will print duplicate results
		}
	}
}

int main()
{
	char input1[] = "abcde";
	char input2[] = "aac";
	printAllPermutation(input1, 0, 4);
	printAllPermutation(input2, 0, 2);
	return 0;
}

