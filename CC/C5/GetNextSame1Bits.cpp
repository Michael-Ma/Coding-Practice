#include <iostream>
#include <string>

using namespace std;

string printIntInBits(int int_p)
{
	string int_s = "";
	while(int_p > 0)
	{
		if(int_s.size() > 32)
		{
			return "ERROR";
		}

		int tmp = int_p%2;
		if(tmp == 1)
		{
			int_s = "1" + int_s;
		}
		else if(tmp == 0)
		{
			int_s = "0" + int_s;
		}
		int_p >>= 1;
	}

	return int_s;
}


//return true if this bit is 1. index starts from 0;
bool checkBits(int source, int index)
{
	int mask = 1<<index;  //mask the bit at index to 1
	return (source & mask) > 0;
}

void setBits(int& source, int index, bool oneOrZero)
{
	if(oneOrZero) // if need to set one
	{
		int mask = 1<<index;  //mask the bit at index to 1
		source = source | mask;
	}else{  //if need to set zero
		int mask = ~(1<<index); //mask the bit at index to 0
		source = source & mask;
	}
}

int getNextSame1_B(int source)
{
	if(source<=0)
	{
		return -1;
	}

	int index = 0;
	int num_1s = 0;
	//1.find the lowest 1
	while(!checkBits(source, index))
	{
		index++;
	}
	//2.find the first 0 after the those 1 or 1s
	while(checkBits(source, index))
	{
		index++;
		num_1s++;
	}
	//3.set this 0 to 1
	setBits(source, index, true);
	num_1s--;  //need to reduce one since we already set one
	//4.set the lowest bits to 1s
	for(int i=0; i<num_1s; i++)
	{
		setBits(source, i, true);
	}
	//5.set the rest bits to 0s
	for(int i=num_1s; i<index; i++)
	{
		setBits(source, i, false);
	}

	return source;
}

int getNextSame1_S(int source)
{
	if(source<=0)
	{
		return -1;
	}

	int index = 0;
	int num_0s = 0;
	//1.find the lowest 0
	while(checkBits(source, index))
	{
		index++;
	}
	//2.find the first 1 after the those 0 or 0s
	while(!checkBits(source, index))
	{
		index++;
		num_0s++;
	}
	//3.set this 1 to 0
	setBits(source, index, false);
	num_0s--;  //need to reduce one since we already set one
	//4.set the lowest bits to 0s
	for(int i=0; i<num_0s; i++)
	{
		setBits(source, i, false);
	}
	//5.set the rest bits to 1s
	for(int i=num_0s; i<index; i++)
	{
		setBits(source, i, true);
	}

	return source;
}


int main()
{
	int input = 70;
	cout<<"next big bits of "<<printIntInBits(input)<<" with same 1s is "<<printIntInBits(getNextSame1_B(input))<<endl;
	cout<<"next small bits of "<<printIntInBits(input)<<" with same 1s is "<<printIntInBits(getNextSame1_S(input))<<endl;
}

