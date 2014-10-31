#include <iostream>

using namespace std;

int mergeBits(int m, int n, int start, int end)
{
	if(start<0 || start>32 || end<0 || end>32)
	{
		return -1;
	}

	int max = ~0; //all 1
	int left = max - (1<<end -1);  //111000000
	int right = 1<<start -1;       //000000011
	int mask = left | right;       //111000011
	
	return (n&mask) | (m<<start);
}

int main()
{
	int m = 21;   //10101
	int n = 193;   //11000001
	cout <<"result is : "<<mergeBits(m, n, 2, 6)<<endl;
}

