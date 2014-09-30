#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmpAnagram(string left, string right)
{
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	for(int i=0; i<left.size() && i<right.size(); i++)
	{
		if(left[i] < right[i])
		{
			return true;
		}else if(left[i] > right[i])
		{
			return false;
		}
	}
	return left.size() < right.size();
}

int main()
{
	vector<string> input;
	input.push_back("adf");
	input.push_back("12s");
	input.push_back("addffg");
	input.push_back("adfgfd");
	input.push_back("addfg");
	sort(input.begin(), input.end(), cmpAnagram);
	for(vector<string>::iterator it=input.begin(); it!=input.end(); it++)
	{
		cout<<*it<<", ";
	}
	cout<<endl;
}

