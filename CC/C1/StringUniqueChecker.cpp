#include <iostream>

using namespace std;

bool isUniqChar(string input)
{
	bool checked[256] = {false};
	for(int i=0; i<input.size(); i++)
	{
		int pos = input.at(i);
		if(checked[pos])
		{
			return false;
		}
		checked[pos] = true;
	}
	return true;
}

int main()
{
	cout<<"abced is unique? A:"<<isUniqChar("abced")<<endl;
	cout<<"aaaa is unique? A:"<<isUniqChar("aaaa")<<endl;
	cout<<"acbcdd is unique? A:"<<isUniqChar("acbcdd")<<endl;
}

