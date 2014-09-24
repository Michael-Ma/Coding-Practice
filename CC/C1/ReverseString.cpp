#include <iostream>

using namespace std;

void reverseStr(char* input)
{
	char* start = input;
	char* end   = input;
	while(*end != '\0')
	{
		end++;
	}
	end--;   //since the last element for string is '\0'
	while(start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main()
{
	char input1[6] = "abcde";
	char input2[5] = "aaaa";
	char input3[6] = "abbed";
	reverseStr(input1);
	reverseStr(input2);
	reverseStr(input3);
	cout<<"abcde -> "<<input1<<endl;
	cout<<"aaaa -> "<<input2<<endl;
	cout<<"abbed -> "<<input3<<endl;
}

