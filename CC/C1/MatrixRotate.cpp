#include <iostream>

using namespace std;

const int N = 10;

void rotateMatrix(int matrix[N][N])
{
	for(int i=0; i<N/2; i++) //for different layers
	{
		int first = i;
		int last = N - 1 - first;
		for(int j=first; j<last; j++) //for each layer
		{
			//four way swap
			int top = matrix[first][j];  //matrix[i][j] is (j, i)!
			matrix[first][j] = matrix[j][N-1-first];
			matrix[j][N-1-first] = matrix[N-1-first][N-1-j];
			matrix[N-1-first][N-1-j] = matrix[N-1-j][first];
			matrix[N-1-j][first] = top;
		}
	}
}

int main()
{
	int input[N][N];
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			input[i][j] = i*j;
			cout<<input[i][j]<<", ";
		}
		cout<<endl;
	}
	rotateMatrix(input);

	cout<<"After rotate:"<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<input[i][j]<<", ";
		}
		cout<<endl;
	}
}

