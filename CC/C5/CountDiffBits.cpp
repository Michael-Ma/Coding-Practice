#include <iostream>

using namespace std;

int countDiffBits(int ll, int rr)
{
	int count = 0;
	for(int xor_r=ll ^ rr; xor_r!=0; xor_r>>=1)
	{
		if(xor_r & 1 == 1)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	cout<<"50 and 38 diff in "<<countDiffBits(50, 38)<<" bits."<<endl;
}

