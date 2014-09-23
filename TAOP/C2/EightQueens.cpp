#include <iostream>
#include <cmath>

using namespace std;

int resCol[8] = {0};

bool checkColForRow(int row)
{
	for(int i=0; i<row; i++)
	{
		int diff = abs(resCol[row] - resCol[i]);
		if(diff==0 || diff==row-i)
		{
			return false;
		}
	}
	return true;
}

void placeQueens(int row)
{
	if(row == 8)
	{
		for(int i=0; i<8; i++)
		{
			cout<<resCol[i]<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i=0; i<8; i++)
	{
		resCol[row] = i;
		if(checkColForRow(row))
		{
			placeQueens(row+1);
		}
	}
}

int main()
{
	placeQueens(0);
	return 0;}
