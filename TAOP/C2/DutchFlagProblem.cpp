#include <iostream>

using namespace std;

void swapFlags(int input[], int size)
{
	int curr=0, begin=0, end=size-1;
	while(curr < end)
	{
		if(input[curr] == 1)
		{
			swap(input[curr], input[begin]);
			curr++;
			begin++;   //curr always >= begin, so no worry about the swaped element.
		}else if(input[curr] == 2)
		{
			curr++;
		}else if(input[curr] == 3)
		{
			swap(input[curr], input[end]);
			end--;   //can't increase curr since you need to worry about the swapped element.
		}
	}
}

int main()
{
	int input[10] = {1, 2, 3, 3, 1, 2, 2, 3, 1, 2};
	swapFlags(input, 10);
	for(int i=0; i<10; i++)
	{
		cout<<input[i]<<", ";
	}
	cout<<endl;
	return 0;
}

