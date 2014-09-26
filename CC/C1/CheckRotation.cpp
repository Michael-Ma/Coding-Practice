#include <iostream>

using namespace std;

//apple and pleap are rotations.
bool isRotation(string left, string right)
{
	string comb = left + left;
	int pos = comb.find(right);
	return pos != std::string::npos;
}

int main()
{
	string left1 = "apple";
	string right1 = "pplea";
	string left2 = "apply phd";
	string right2 = "phd apply";
	cout<<left1<<", "<<right1<<" : "<<isRotation(left1, right1)<<endl;
	cout<<left2<<", "<<right2<<" : "<<isRotation(left2, right2)<<endl;
	return 0;
}

