#include <iostream>
#include <cstring>

using namespace std;

bool isComposedBy(const char* s1, const char* s2, const char* s3)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len3 = strlen(s3);

	if(len1+len2 != len3)
	{
		return false;
	}

	bool d[len1+1][len2+1];  //d[i][j] means is (0, i+j-1) from s3 composed by (0, i) of s1 and (0, j) of s2 
	//need to init, otherwise result will be not correct.
	for(int i=0; i<len1+1; i++)
	{
		for(int j=0; j<len2+1; j++)
		{
			d[i][j] = false;
		}
	}

	d[0][0] = true;          //init case

	for(int i=0; i<len1+1; i++)
	{
		for(int j=0; j<len2+1; j++)
		{
			if(d[i][j] || ((i>0)&&(s1[i-1]==s3[i+j-1])&&d[i-1][j]==true) || ((j>0)&&(s2[j-1]==s3[i+j-1])&&d[i][j-1]==true) )
			{
				d[i][j] = true;
			}else{
				d[i][j] = false;
			}
		}
	}

	return d[len1][len2];
}

int main()
{
	const char* s1 = "aabcc";
	const char* s2 = "dbbca";
	const char* s3 = "aadbbcbcac";
	const char* s4 = "accabdbbcc";

	cout<<s3<<" : "<<isComposedBy(s1, s2, s3)<<endl;
	cout<<s4<<" : "<<isComposedBy(s1, s2, s4)<<endl;
}
