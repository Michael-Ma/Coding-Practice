#include <iostream>

using namespace std;

int findNumShowHalfArray(int input[], int size)
{
	int candidate = input[0];
	int showTime = 1;
	for(int i=1; i<size; i++)
	{
		if(showTime == 0)
		{
			candidate = input[i];
			showTime = 1;
		}

		if(candidate == input[i])
		{
			showTime++;
		}else{
			showTime--;
		}
	}
	return candidate;
}

int main()
{
	int input[10] = { 1, 3, 2, 2, 2, 9, 0, 2, 2, 2};
	cout<<"num showed more than half of the array length is "<<findNumShowHalfArray(input, 10)<<endl;
}

