#include <iostream>

using namespace std;

const int N = 10;
enum Color{ white, black, red, yellow, green, blue };

void paintFill(Color screen[N][N], int x, int y, Color old_c, Color new_c)
{
	if(x<0 || x>=N || y<0 || y>=N)
	{
		return;
	}

	if(screen[x][y] == old_c)
	{
		screen[x][y] = new_c;
		paintFill(screen, x, y+1, old_c, new_c);
		paintFill(screen, x, y-1, old_c, new_c);
		paintFill(screen, x+1, y, old_c, new_c);
		paintFill(screen, x-1, y, old_c, new_c);
	}
}

int main()
{
	Color screen[N][N] = {white};
	screen[2][3] = black;
	screen[2][4] = black;
	screen[2][5] = black;
	screen[3][3] = black;
	screen[3][4] = black;
	screen[3][5] = black;
	paintFill(screen, 0, 0, screen[0][0], green);

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<screen[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

