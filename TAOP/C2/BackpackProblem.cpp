#include <iostream>
#include <list>

using namespace std;

static list<int> result;
void sumOfKNumber(int sum, int n)
{
	if(sum<=0 || n<=0)
	{
		return;
	}

	if(n == sum)
	{
		result.reverse();
		for(list<int>::iterator iter=result.begin(); iter!=result.end(); iter++)
		{
			cout<<*iter<<" + ";
		}
		cout<<n<<endl;
		result.reverse();
	}

	//if we put n into the final result.
	result.push_back(n);
	sumOfKNumber(sum-n, n-1);
	//if we don't put n into the final result.
	result.pop_back();
	sumOfKNumber(sum, n-1);
}

int main()
{
	sumOfKNumber(15, 10);
	return 0;
}

