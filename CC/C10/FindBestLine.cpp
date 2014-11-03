#include <iostream>
#include <cmath>
#include <map>

using namespace std;

const double epsilon = 0.00001;

struct Point
{
	double x;
	double y;
}

class Line
{
  public:
	double slope;
	double intercept;  //intercept with y axis
	bool infinit_slope;

	Line(Point& a, Point& b)
	{
		if(abs(a.x-b.x) > epsilon)
		{
			slope = (a.y-b.y)/(a.x-b.x);
			intercept = a.y - slope*a.x;
			infinit_slope = false;
		}else{
			intercept = a.x
			infinit_slope = true;
		}
	}
}

Line findBestLine()
{

}

int main()
{

}

