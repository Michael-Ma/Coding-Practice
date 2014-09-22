#include <iostream>
#include <string>
#include <vector>

using namespace std;

string insertCharAt(string base, char c, int pos)
{
	string begin = base.substr(0, pos);
	string end = base.substr(pos);
	return begin + string(1, c) + end;
}

vector<string> getAllPermutation(string input)
{
	vector<string> result;
	if(input.length() == 0)
	{
		result.push_back("");
		return result;
	}

	char c = input.at(0);   //pick first char is enough, since we will insert it to all the possible pos.
	string remain = input.substr(1);
	vector<string> subPerm = getAllPermutation(remain);
	for(int i=0; i<subPerm.size(); i++)
	{
		for(int j=0; j<=subPerm[i].length(); j++)
		{
			result.push_back(insertCharAt(subPerm[i], c, j));
		}
	}

	return result;
}

int main()
{
	vector<string> res = getAllPermutation("mxc");
	for(int i=0; i<res.size(); i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}

