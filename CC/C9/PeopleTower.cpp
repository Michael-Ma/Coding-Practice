#include <iostream>
#include <algorithm>

using namespace std;

struct people
{
	int h;
	int w;
};

typedef struct people People;

static bool cmp_people(People left, People right)
{
	return left.h < right.h;
}

int findLIS(People pe[], int size)
{
	int wList[size];
	int wSize = 1;
	wList[0] = pe[0].w;
	for(int i=1; i<size; i++)
	{
		// if next people is valid
		if(pe[i].w > wList[wSize-1])
		{
			wSize++;
			wList[wSize-1] = pe[i].w;
		}
		else
		{
			int j;
			for(j=wSize-1; wList[j]>pe[i].w && j>=0; j--);  //find the right pos for next possibile iteration
			wList[j+1] = pe[i].w;   //set value for that pos
		}
	}
	return wSize;
}

int main()
{
	People input[8];
	for(int i=0; i<8; i++)
	{
		input[i].h = 60+i*2;
		input[i].w = 50+i*5;
	}
	input[3].h = 30;
	input[3].w = 70;
	input[5].h = 70;
	input[5].w = 30;
	for(int i=0; i<8; i++)
	{
		cout <<"( "<<input[i].h<<", "<<input[i].w<<") ";
	}
	cout<<endl;
	sort(input, input+8, cmp_people);
	cout<<"result is : "<<findLIS(input, 8)<<endl;
}

