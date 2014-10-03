#include <iostream>
#include <string>

using namespace std;

int sparedBinarySort(string input[], int from, int to, string target)
{
	while(input[from] == "")
	{
		from++;
	}
	while(input[to] == "")
	{
		to--;
	}
	
	//need to check after moving the needle 
	if(from > to)
	{
		return -1;
	}

	int pivot = (from + to)/2;
	while(input[pivot] == "")
	{
		pivot++;
	}

	int result = 0;
	if(input[pivot].compare(target) > 0)
	{
		result = sparedBinarySort(input, from, pivot-1, target);
	}
	else if(input[pivot].compare(target) < 0)
	{
		result = sparedBinarySort(input, pivot+1, to, target);
	}else
	{
		result = pivot;
	}

	return result;
}

int main()
{
	string input[15] = {"", "abc", "", "", "", "gg", "ll", "", "", "", "", "look", "", "", "xyz"};
	cout<<"pos of gg is "<<sparedBinarySort(input, 0, 14, "gg")<<endl;
	cout<<"pos of xyz is "<<sparedBinarySort(input, 0, 14, "xyz")<<endl;
	cout<<"pos of fuck is "<<sparedBinarySort(input, 0, 14, "fuck")<<endl;
}

