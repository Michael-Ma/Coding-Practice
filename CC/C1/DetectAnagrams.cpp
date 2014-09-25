#include <iostream>

using namespace std;

//anagram are two words with same set of chars, but different order
bool detectAnagram(string left, string right)
{
	if(left.length() != right.length())
	{
		return false;
	}

	int checked[256] = {0};
	for(int i=0; i<left.length(); i++)
	{
		char c = left.at(i);
		checked[c]++;
	}
	for(int i=0; i<right.length(); i++)
	{
		char c = right.at(i);
		if(checked[c] == 0)
		{
			return false;
		}
		checked[c]--;
	}
	return true;
}

int main()
{
	cout<<"Q: Are abcsd and addd anagram? A:"<<detectAnagram("abcsd", "addd")<<endl;
	cout<<"Q: Are abcsd and adsbc anagram? A:"<<detectAnagram("abcsd", "adsbc")<<endl;
	cout<<"Q: Are aaaaa and aaa anagram? A:"<<detectAnagram("aaaaa", "aaa")<<endl;
	return 0;
}
