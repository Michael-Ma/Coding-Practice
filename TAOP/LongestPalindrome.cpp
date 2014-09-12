#include <stdio.h>
#include <iostream>

using namespace std;

int getLongestPalindromeSize(const char* input, int size)
{
	if(input==NULL || size<1)
	{
		return 0;
	}

	int max = 0;
	for(int i=0; i<size; i++)
	{
		int tempMax = 0;
		//for odd case
		for(int j=0; (i-j)>=0 && (i+j)<size; j++)
		{
			if(input[i-j] != input[i+j])
			{
				break;
			}
			tempMax = 2*j + 1;
		}
		if(max < tempMax)
		{
			max = tempMax;
		}
		//for even case
		for(int j=0; (i-j)>=0 && (i+j+1)<size; j++)
		{
			if(input[i-j] != input[i+j+1])
			{
				break;
			}
			tempMax = j*2 + 2;
		}
		if(max < tempMax)
		{
			max = tempMax;
		}
	}
	return max;
}


int main()
{
	const char* input1 = "adbweewr";
	const char* input2 = "adbwedewr";
	const char* input3 = "aaaaaaaaaa";
	cout<<"length of input1 palindrome = "<<getLongestPalindromeSize(input1, 8)<<endl;
	cout<<"length of input2 palindrome = "<<getLongestPalindromeSize(input2, 9)<<endl;
	cout<<"length of input3 palindrome = "<<getLongestPalindromeSize(input3, 10)<<endl;
	return 0;
}

