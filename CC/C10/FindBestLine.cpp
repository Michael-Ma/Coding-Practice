#include <iostream>
#include <cmath>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

const double epsilon = 0.00001;

struct Point
{
	double x;
	double y;
};

class Line
{
  public:
	double slope;
	double intercept;  //intercept with y axis
	bool infinit_slope;

	Line() {}
	Line(Point& a, Point& b)
	{
		if(abs(a.x-b.x) > epsilon)
		{
			slope = (a.y-b.y)/(a.x-b.x);
			intercept = a.y - slope*a.x;
			infinit_slope = false;
		}else{
			intercept = a.x;
			infinit_slope = true;
		}
	}

	void print()
	{
		cout<<"slope = "<<slope<<", intercept = "<<intercept<<", infinit_slope = "<<infinit_slope<<" ."<<endl;
	}

	int hashCode() const
	{
		int sl_h = (int) (slope*1000);
		int in_h = (int) (intercept*1000);
		return in_h*1000 + sl_h + infinit_slope;
	}

	bool operator < (const Line& right) const
	{
		return this->hashCode() < right.hashCode();
	}
};

// remember it's how to compare 2 doubles.
bool isEqual(double x, double y)
{
	return abs(x-y) < epsilon;
}

Line findBestLine(Point points[], int size)
{
	Line* result = NULL;
	map<Line, int> lineMap; 
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			Line tmp(points[i], points[j]);
			lineMap[tmp]++;

			if(result==NULL || lineMap[*result] < lineMap[tmp])
			{
				result = &tmp;
			}
		}
	}
	cout<<"num of points it passes is "<<lineMap[*result] + 1<<endl;
	return *result;
}

int main()
{
	srand((unsigned)time(0));
	int size = 500;
	Point points[size];
	for(int i=0; i<size; i++)
	{
		points[i].x = rand()%100;
		points[i].y = rand()%100;
	}
	Line res = findBestLine(points, size);
	res.print();
}

