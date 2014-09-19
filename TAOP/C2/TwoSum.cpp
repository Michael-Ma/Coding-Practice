#include <iostream>
#include <stdio.h>

using namespace std;

void printTwoSum(int input[], int size, int sum)
{
	int start = 0;
	int end = size - 1;

	while(start < end)
	{
		if(input[start] + input[end] == sum)
		{
			cout<<"Two num with sum = "<<sum << " is: "<< input[start] << ", " << input[end] <<endl;
			break;
		}else if(input[start] + input[end] < sum)
		{
			start++;
		}else
		{
			end--;
		}
	}
}


int main()
{
	int input1[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14, 19, 22, 24, 25, 29, 32};
	int input2[17] = {1, 2, 5, 6, 7, 8, 9, 11, 13, 14, 19, 20, 22, 24, 25, 29, 32};
	printTwoSum(input1, 17, 17);
	printTwoSum(input2, 17, 27);
	return 0;
}

