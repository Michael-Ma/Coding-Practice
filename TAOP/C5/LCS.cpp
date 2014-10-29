// LCS is Longest Common Substring.

#include <iostream>
#include <algorithm>

using namespace std;

double getLCS(double input[], int size)
{
	double result;
	double MIN;   //MIN is used for those cases with negative number
	double MAX;

	//value for init.
	MIN = input[0];
	MAX = input[0];
	result = input[0];

	for(int i=1; i<size; i++)
	{
		double min_r = MIN * input[i];
		double max_r = MAX * input[i];
		MIN = min(min(min_r, max_r), input[i]);
		MAX = max(max(min_r, max_r), input[i]);
		result = max(result, MAX);
		//cout<<"i="<<i<<", MIN="<<MIN<<", MAX="<<MAX<<", result="<<result<<endl;
	}
	return result;
}

int main()
{
	double input[12] = {0.9, 3, 5, -9, 0, -8, 0.01, 10, -10000, 0.3, -0.8, 23};
	cout<<"Longest Common Substring of input is "<<getLCS(input, 12)<<endl;
}

