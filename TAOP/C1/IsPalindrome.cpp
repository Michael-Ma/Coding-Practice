#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * palindrome is a string like "abcba".
 */
bool isPalindrome(const char* input, int size)
{
	if(input == NULL || size < 1){
		return false;
	}

	const char* front = input;
	const char* back  = input+size-1;
	while(front < back)
	{
		if(*front != *back)
		{
			return false;
		}
		front++;
		back--;
	}

	return true;
}

int main()
{
	const char* input1 = "asdfewer";
	const char* input2 = "asdfdsa";
	const char* input3 = "aaaaa";

	if(isPalindrome(input1, 8))
	{
		cout<<input1<<" is palindrome."<<endl;
	}
	if(isPalindrome(input2, 7))
	{
		cout<<input2<<" is palindrome."<<endl;
	}
	if(isPalindrome(input3, 5))
	{
		cout<<input3<<" is palindrome."<<endl;
	}
}

