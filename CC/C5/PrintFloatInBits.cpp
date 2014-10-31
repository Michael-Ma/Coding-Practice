#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string printFloatInBits(string& input)
{
	if(input.at(0) == '-')
	{
		return "don't support negative number";
	}

	int pos = input.find('.');
	int int_p = atoi(input.substr(0, pos).c_str());
	cout<<"int_p : "<<input.substr(0, pos)<<" -> "<<int_p<<endl;
	double dec_p = atof(("0"+input.substr(pos, input.size()-pos)).c_str());  // attention: atof need .34 part!
	cout<<"dec_p : "<<input.substr(pos, input.size()-pos)<<" -> "<<dec_p<<endl;
	string int_s = "";
	string dec_s = "";
	
	//convert int part
	while(int_p > 0)
	{
		if(int_s.size() > 32)
		{
			return "ERROR";
		}

		int tmp = int_p%2;
		if(tmp == 1)
		{
			int_s = "1" + int_s;
		}
		else if(tmp == 0)
		{
			int_s = "0" + int_s;
		}
		int_p >>= 1;
	}
	//convert decimal part
	while(dec_p > 0)
	{
		if(dec_s.size() > 32)
		{
			return "ERROR";
		}

		dec_p *= 2;
		if(dec_p >= 1)
		{
			dec_s += "1";
			dec_p -= 1;
		}else{
			dec_s += "0";
		}
	}

	return int_s + "." + dec_s;
}

int main()
{
	string input1 = "24.25";
	string input2 = "-24.25";
	cout<<input1<<" -> "<<printFloatInBits(input1)<<endl;
	cout<<input2<<" -> "<<printFloatInBits(input2)<<endl;
}

