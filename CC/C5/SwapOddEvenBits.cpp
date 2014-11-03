#include <iostream>

using namespace std;

int swapOddEvenBits(int input)
{
	int odds = input & 0x55555555;
	int evens = input & 0xAAAAAAAA;
	return (odds<<1) | (evens>>1);
}

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


int main()
{
	cout<<"swap "<<printIntInBits(52)<<" is "<<printIntInBits(swapOddEvenBits(52))<<endl;
}

