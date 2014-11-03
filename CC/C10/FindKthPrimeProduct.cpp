#include <iostream>
#include <queue>

using namespace std;

int findKthPrimeProduct(int k)
{
	if(k <= 0)
	{
		return 0;
	}

	int val = 1;
	queue<int> q3;
	queue<int> q5;
	queue<int> q7;

	q3.push(3);
	q5.push(5);
	q7.push(7);
	for(k--; k>0; k--)
	{
		int v3 = q3.front();
		int v5 = q5.front();
		int v7 = q7.front();
		val = min(min(v3, v5), v7);
		if(val == v3)
		{
			q3.pop();
			q3.push(val*3);
			q5.push(val*5);
			q7.push(val*7);
		}
		else if(val == v5)
		{
			q5.pop();
			q5.push(val*5);
			q7.push(val*7);
		}
		else if(val == v7)
		{
			q7.pop();
			q7.push(val*7);
		}
	}
	return val;
}

int main()
{
	for(int i=1; i<10; i++)
	{
		cout<<findKthPrimeProduct(i)<<", "<<endl;
	}
	cout<<endl;
}

