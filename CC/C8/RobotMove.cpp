#include <iostream>
#include <list>
#include <string>
#include <stdio.h>

using namespace std;

const int N = 5; 

bool limit[N][N];

struct point
{
	int _x;
	int _y;
	point():_x(0), _y(0) {}
	point(int x, int y):_x(x), _y(y) {}

	string toString() 
	{ 
		char temp1[30];
		char temp2[30];
		sprintf(temp1, "%d", _x);
		sprintf(temp2, "%d", _y);
		return string("(") + temp1 + string(", ") + temp2 + string(")");
	}
};
typedef struct point point_t;

list<point_t> path;


void moveRobot(int x, int y)
{
	if(x==N-1 && y==N-1)
	{
		for(list<point_t>::iterator it=path.begin(); it!=path.end(); it++)
		{
			cout<<it->toString()<<" -> ";
		}
		cout<<endl;
		return;
	}else if(x>=N || y>=N)
	{
		return;
	}

	if(x<N-1 && limit[x+1][y])
	{
		path.push_back(point_t(x+1, y));
		moveRobot(x+1, y);
		path.pop_back();
	}
	if(y<N-1 && limit[x][y+1])
	{
		path.push_back(point_t(x, y+1));
		moveRobot(x, y+1);
		path.pop_back();
	}
}

int main()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			limit[i][j] = true;
		}
	}
	limit[0][3] = false;
	limit[3][2] = false;

	moveRobot(0, 0);
}

