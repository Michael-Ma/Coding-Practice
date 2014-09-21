#include <stdio.h>
#include <iostream>

using namespace std;

void reverse(int input[], int start, int end)
{
	while(start < end)
	{
		swap(input[start], input[end]);
		start++;
		end--;
	}
}

void swapReverse(int input[], int start, int mid, int end)
{
	reverse(input, start, mid-1);
	reverse(input, mid, end);
	reverse(input, start, end);
}

bool isOdd(int input)
{
	return input%2 == 1;
}

//but odd in front of even, and make sure order is stable.
void swapOddEvenStably(int input[], int size)
{
	int start=0, mid=0, end=0;
	while(isOdd(input[start])){ start++; }   //find start
	mid = start;
	while(end < size)
	{
		while(!isOdd(input[mid])){ mid++; }   //find as many as even as possible
		end = mid;
		while(isOdd(input[end])){ end++; }   //find as many as odd as possible
		swapReverse(input, start, mid, end);
		//calculate new start, mid
		start += end - mid;
		mid = end;
		end++;
	}
}

int main()
{
	int input[20] = { 2, 3, 5, 23, 6, 9, 10, 7, 3, 7, 12, 20, 30, 44, 32, 0, 1, 13, 2, 41};
	swapOddEvenStably(input, 20);
	for(int i=0; i<20; i++)
	{
		cout<<input[i]<<", ";
	}
	cout<<endl;
	return 0;
}

