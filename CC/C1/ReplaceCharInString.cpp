#include <iostream>

using namespace std;

string replaceSpaceInStr(string input)
{
	string result = "";
	for(int i=0; i<input.size(); i++)
	{
		if(input.at(i) == ' ')
		{
			result.push_back('%');
			result.push_back('2');
			result.push_back('0');
		}else{
			result.push_back(input.at(i));
		}
	}
	return result;
}

int main()
{
	string output1 = replaceSpaceInStr("a b c sef  g");
	cout<<"\"a b c sef  g\" -> "<<output1<<endl;
}
