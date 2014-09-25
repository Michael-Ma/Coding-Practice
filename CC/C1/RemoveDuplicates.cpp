#include <iostream>

using namespace std;

void removeDup(char* input)
{
	if(input==NULL || *input=='\0')
	{
		return;
	}
	char* tail = input+1;
	char* end = tail;
	while(*end != '\0')
	{
		char* i=input;
		for(; i<tail; i++)
		{
			if(*end == *i)
			{
				break;
			}
		}
		if(tail==i)
		{
			*tail = *end;
			tail++;
		}
		end++;
	}
	*tail = '\0';
}

int main()
{
	char input1[5] = "aaaa";
	char input2[7] = "acedrg";
	char input3[8] = "aaabebb";
	removeDup(input1);
	removeDup(input2);
	removeDup(input3);
	cout<<"aaaa after removeDup : "<<input1<<endl;
	cout<<"acedrg after removeDup : "<<input2<<endl;
	cout<<"aaabebb after removeDup : "<<input3<<endl;

	return 0;
}

