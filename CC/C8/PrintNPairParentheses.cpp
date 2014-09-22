#include <iostream>

using namespace std;

void printAllParentheses(char res[], int l, int r, int pos)
{
	if(l<0 || r < l)
	{
		return;
	}
	else if(r==0 && l==0)
	{
		cout<<res<<endl;
	}
	else
	{
		if(l>0)
		{
			res[pos] = '(';
			printAllParentheses(res, l-1, r, pos+1); 
		}
		if(r>0)
		{
			res[pos] = ')';
			printAllParentheses(res, l, r-1, pos+1); 
		}
	}
}

int main()
{
	char input[6];
	printAllParentheses(input, 3, 3, 0);
	return 0;
}

