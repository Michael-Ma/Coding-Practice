#include <iostream>
#include <stdio.h>

using namespace std;

static const int MAX_INT = (int) ((unsigned)~0 >> 1);
static const int MIN_INT =  - (int) ((unsigned)~0 >> 1) - 1;

int strToInt(const char* input)
{
	if(input == NULL)
	{
		return 0;
	}

	bool sign = true;
	int  result = 0;

	if(input[0] == '-')
	{
		sign = false;
	}

	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i] == '-' || input[i] == '+')
		{
			continue;
		}

		int add = input[i] - '0';
		if(sign && (result > MAX_INT/10 || (result==MAX_INT/10 && add>MAX_INT%10)))
		{
			result = MAX_INT;
			break;
		}
		if(!sign && (result > (unsigned)MIN_INT/10 || (result==(unsigned)MIN_INT/10 && add>(unsigned)MIN_INT%10)))
		{
			result = MIN_INT;
			break;
		}

		result *= 10;
		result += add;
	}
	if(!sign && result>0)
	{
		result *= -1;
	}

	return result;
}

int main()
{
	const char* input1 = "1234";
	const char* input2 = "-1234";
	const char* input3 = "+1234";
	const char* input4 = "+12343242393423";
	cout<<"input1 = "<<strToInt(input1)<<endl;
	cout<<"input2 = "<<strToInt(input2)<<endl;
	cout<<"input3 = "<<strToInt(input3)<<endl;
	cout<<"input4 = "<<strToInt(input4)<<endl;
	return 0;
}

