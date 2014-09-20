#include <stdio.h>
#include <iostream>

using namespace std;

unsigned int calcFibonacci(unsigned int n)
{
	if(n < 2)
	{
		return 1;
	}

	int temp[3] = {1,1};
	for(int i=2; i<n; i++)
	{
		temp[2] = temp[0] + temp[1];
		temp[0] = temp[1];
		temp[1] = temp[2];
	}
	return temp[2];
}


unsigned int calcAdvFibonacci(unsigned int n)
{
	if(n < 2)
	{
		return 1;
	}

	int temp[n+1];
	temp[0] = 1;
	int type[4] = {1, 2, 5, 10};
	for(int i=2; i<n; i++)
	{
		for(int j=0; type[j]<=i && j<4; j++)
		temp[i] += temp[ i - type[j] ];
	}
	return temp[2];
}


int main()
{
	cout<<"Fibonacci of 100 is:"<<calcFibonacci(100)<<endl;
	cout<<"Advanced Fibonacci of 100 is:"<<calcAdvFibonacci(100)<<endl;
	return 0;

}


