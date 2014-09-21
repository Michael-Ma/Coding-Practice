#include <iostream>

using namespace std;

void multiplyMatrix(int left[4][3], int l_col, int l_row, int right[3][5], int r_col, int r_row, int result[4][5])
{
	if(l_col != r_row)
	{
		return;
	}

	for(int i=0; i<l_row; i++)
	{
		for(int j=0; j<r_col; j++)
		{
			result[i][j] = 0;
			for(int k=0; k<l_col; k++)
			{
				result[i][j] += left[i][k] * right[k][j];
			}
		}
	}
}

int main()
{
	int left[4][3];
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<3; j++)
		{
			left[i][j] = 1;
		}
	}
	int right[3][5];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<5; j++)
		{
			right[i][j] = 1;
		}
	}
	int result[4][5];

	multiplyMatrix(left, 3, 4, right, 5, 3, result);

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

