#include <iostream>
#include <stdio.h>

using namespace std;

int getMaxSubArray(int source[], int size)
{
	int maxSum=source[0], curSum=0;
	for(int i=0; i<size; i++)
	{
		curSum = curSum+source[i]>source[i] ? curSum+source[i] : source[i];
		maxSum = maxSum>curSum ? maxSum : curSum;
	}
	return maxSum;	
}

int main()
{
	int input1[10] = {0, 1, 4, 5, -9, -23, 99, 3, -4, 5};
	int input2[10] = {-20, -1, -4, -5, -9, -23, -99, -3, -4, -5};
	int input3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	cout<<"max sub arrary of input1 is:"<<getMaxSubArray(input1, 10)<<endl;
	cout<<"max sub arrary of input2 is:"<<getMaxSubArray(input2, 10)<<endl;
	cout<<"max sub arrary of input3 is:"<<getMaxSubArray(input3, 10)<<endl;
	
}

