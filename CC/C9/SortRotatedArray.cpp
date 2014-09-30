#include <iostream>

using namespace std;

int searchRotatedArray(int input[], int left, int right, int value)
{
	while(left <= right)
	{
		int pivot = (left + right)/2;
		if(value == input[pivot])
		{
			return pivot;
		}
		else if(input[pivot] >= input[left])
		{
			if(value > input[pivot])
			{
				left = pivot + 1;
			}else if(value < input[left])
			{
				left = pivot + 1;
			}else
			{
				right = pivot -1;
			}
		}else
		{
			if(value > input[right])
			{
				right = pivot - 1;
			}else if(value < input[pivot])
			{
				right = pivot - 1;
			}else
			{
				left = pivot + 1;
			}
		}
	}
	return -1;
}

int main()
{
	int input[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	cout<<"pos of 15 is : "<<searchRotatedArray(input, 0, 11, 15)<<endl;
	cout<<"pos of 14 is : "<<searchRotatedArray(input, 0, 11, 14)<<endl;
	cout<<"pos of 1 is : "<<searchRotatedArray(input, 0, 11, 1)<<endl;
}

