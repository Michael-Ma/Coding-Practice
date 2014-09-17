#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

/*
 * check if a has all the char inside b.
 */
bool stringContain(string& a, string& b)
{
	map<char, int> dic;
	for(int i=0; i<a.size(); i++)
	{
		dic[a[i]] = 1;
	}
	for(int i=0; i<b.size(); i++)
	{
		if(dic[b[i]] != 1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string a = "wefweosese";
	string b1 = "wes";
	string b2 = "wefuse";

	if(stringContain(a, b1))
	{
		cout<<"a contains b1"<<endl;
	}
	if(stringContain(a, b2))
	{
		cout<<"a contains b2"<<endl;
	}

	return 0;
}

