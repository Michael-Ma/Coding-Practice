#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
const int INF = 1000000;
/*
 * 1st : total step num
 * 2nd : first walk's step num for going down
 * 3rd : second walk's step num for going down
 */
int d[N*2][N][N];    

bool isValid(int step, int x1, int x2)
{
	int y1 = step - x1;
	int y2 = step - x2;
	return (x1<N)&&(x1>=0)&&(x2<N)&&(x2>=0)&&(y1<N)&&(y1>=0)&&(y2<N)&&(y2>=0);
}

int getValue(int step, int x1, int x2)
{
	if(isValid(step, x1, x2))
	{
		return d[step][x1][x2];
	}else{
		return -INF;
	}
}

int getMaxMatrixPath(int input[N][N])
{
	//init
	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			d[0][i][j] = -INF;
		}
	}
	d[0][0][0] = input[0][0];

	for(int k=1; k<=2*N-2; k++)  //2*N-2 is the final step num to go
	{
		for(int i=0; i<N; i++)
		{
			for(int j=i; j<N; j++)  // the other half is the same
			{
				d[k][i][j] = -INF;
				if(!isValid(k, i, j))
				{
					continue;
				}

				if(i!=j)
				{
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i, j));
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i-1, j));
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i, j-1));
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i-1, j-1));
					d[k][i][j] += input[i][k-i] + input[j][k-j];
				}else{
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i, j));
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i-1, j));
					d[k][i][j] = max(d[k][i][j], getValue(k-1, i-1, j-1));
					d[k][i][j] += input[i][k-i];
				}
			}
		}
	}

	return d[2*N-2][N-1][N-1];
}


int main()
{
	int input[N][N];
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			input[i][j] = i+j;
		}
	}

	cout<<"max length can get from 2 roundtrip inside matrix is "<<getMaxMatrixPath(input)<<endl;
}

