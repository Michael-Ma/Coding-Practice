#include <iostream>
#include <stdio.h>

using namespace std;

void quickSelectFirstKElem(int input[], int k, int from, int to)
{
	if(from >= to)
	{
		return;
	}

	int pivot = input[(from+to)/2]; //pivot should be an element inside the array!
	int i = from;
	int j = to;
	while(true)
	{
		while(input[i] < pivot)
		{
			i++;
		}
		while(input[j] > pivot)
		{
			j--;
		}
		if(i < j)
		{
			swap(input[i], input[j]);
		}else{
			break;
		}
		
	}

	if(k < i+1)
	{
		quickSelectFirstKElem(input, k, from, i-1);
	}else if( k > i+1)
	{
		quickSelectFirstKElem(input, k, i+1, to);
	}
	//else, k=i+1 means exact k min elements on one side.
}


int main()
{
	int input[10] = {2, 24, 2, 89, 6, 9, 0, 33, 24, 7};
	quickSelectFirstKElem(input, 4, 0, 9);
	for (int i=0; i<10; i++)
	{
		cout<<input[i] << " -> ";
	}
	return 0;
}
