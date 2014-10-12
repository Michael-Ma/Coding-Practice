#include <iostream>

using namespace std;

int binarySearch(int input[], int start, int end, int res)
{
	if(start > end)
	{
		return -1;
	}

	int pos;
	int mid = (start+end)/2;
	if(input[mid] == res)
	{
		pos = mid;
	}else if(input[mid] < res)
	{
		pos = binarySearch(input, mid+1, end, res);
	}else
	{
		pos = binarySearch(input, start, mid-1, res);
	}
	return pos;
}

int main()
{
	int input[8] = {-3, 0, 1, 2, 5, 6, 9, 14};
	cout<<"5 is at "<<binarySearch(input, 0, 7, 5)<<endl;
	cout<<"-3 is at "<<binarySearch(input, 0, 7, -3)<<endl;
	cout<<"14 is at "<<binarySearch(input, 0, 7, 14)<<endl;
}

