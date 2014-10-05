#include <iostream>

using namespace std;

const int M = 6;
const int N = 5;

bool searchMatrix(int input[M][N], int target)
{
	int m = M-1;
	int n = 0;
	while (m>=0 && n<=N-1)
	{
		if(input[m][n] == target)
		{
			return true;
		}
		else if(input[m][n] > target)
		{
			m--;
		}
		else
		{
			n++;
		}
	}
	return false;
}

int main()
{
	int input[M][N];
	for (int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			input[i][j] = i + j*2;
			cout<<input[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<"search for 13 is: "<<searchMatrix(input, 13)<<endl;
}

