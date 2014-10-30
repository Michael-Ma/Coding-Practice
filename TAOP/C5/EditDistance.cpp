#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int editDistance(const char* source, const char* target)
{
	int sLen = strlen(source);
	int tLen = strlen(target);
	int d[sLen+1][tLen+1];   //d[i][j] edit distance between 0-i in source wiht 0-j in target

	//init case
	for(int i=0; i<sLen+1; i++)
	{
		d[i][0] = i;
	}
	for(int i=0; i<tLen+1; i++)
	{
		d[0][i] = i;
	}

	for(int i=1; i<sLen+1; i++)
	{
		for(int j=1; j<tLen+1; j++)
		{
			if(source[i-1] == target[j-1]) //since string start from 0, i-1 actually means ith char
			{
				d[i][j] = d[i-1][j-1];
			}else{
				d[i][j] = min(min(d[i][j-1]+1, d[i-1][j]+1), d[i-1][j-1]+1);
			}
		}
	}
	return d[sLen][tLen];
}

int main()
{
	const char* source = "abcde";
	const char* target = "aacccd";
	cout<<"Edit distance between "<<source<<" and "<<target<<" is : "<<editDistance(source, target)<<endl;
}

