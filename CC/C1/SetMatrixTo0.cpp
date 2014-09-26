#include<iostream>
#include<vector>

using namespace std;

const int N = 10;
const int M = 8;
void setMatrixTo0(int matrix[M][N])
{
	vector<int> cols;
	vector<int> rows;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(matrix[i][j] == 0)
			{
				cols.push_back(j);
				rows.push_back(i);
			}
		}
	}

	for(int i=0; i<cols.size(); i++)
	{
		int col = cols[i];
		for(int j=0; j<M; j++)
		{
			matrix[j][col] = 0;
		}
	}
	for(int i=0; i<rows.size(); i++)
	{
		int row = rows[i];
		for(int j=0; j<N; j++)
		{
			matrix[row][j] = 0;
		}
	}
}

int main()
{
	int matrix[M][N];
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			matrix[i][j] = 1;
		}
	}
	matrix[4][6] = 0;
	matrix[3][9] = 0;
	setMatrixTo0(matrix);

	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<matrix[i][j]<<", ";
		}
		cout<<endl;
	}
	return 0;
}


