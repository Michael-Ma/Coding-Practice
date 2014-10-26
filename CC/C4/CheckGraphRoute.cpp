#include <iostream>
#include <queue>

using namespace std;

enum State
{
	Visited = 0,
	Unvisited,
};

const int N = 10;
bool  graph[N][N];
State visited[N];
queue<int> visitQueue;

void init()
{
	for(int i=0; i<N; i++)
	{
		visited[i] = Unvisited;
		for(int j=0; j<N; j++)
		{
			graph[i][j] = false;   //true means there is a path from i to j, false otherwise.
		}
	}
}

bool isRouteExistInGraph(int from, int to)
{
	visitQueue.push(from);

	while(!visitQueue.empty())
	{
		int cur = visitQueue.front();
		visitQueue.pop();
		//check every node cur connected with.
		for(int i=0; i<N; i++)
		{
			if(graph[cur][i])
			{
				if(i == to)
				{
					return true;
				}
				if(visited[i] == Unvisited)
				{
					visitQueue.push(i);
				}
			}
		}
		visited[cur] = Visited;
	}

	return false;
}

int main()
{
	init();
	graph[0][1] = true;
	graph[0][2] = true;
	graph[1][2] = true;
	graph[1][4] = true;
	graph[2][3] = true;
	graph[2][6] = true;
	graph[3][4] = true;
	graph[3][6] = true;
	graph[4][5] = true;
	graph[4][8] = true;
	graph[5][3] = true;
	graph[6][5] = true;
	graph[6][3] = true;
	graph[7][5] = true;
	graph[7][8] = true;
	graph[8][9] = true;
	graph[9][7] = true;
	
	cout<<"Route from 0 to 5 is "<<isRouteExistInGraph(0, 5)<<endl;
	cout<<"Route from 5 to 0 is "<<isRouteExistInGraph(5, 0)<<endl;
}

