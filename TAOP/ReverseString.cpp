#include <stdio.h>
#include <iostream>

using namespace std;

void reverseString(char* src, int from, int to)  //assume user will make sure from < to.
{
	while(from < to)
	{
		//swap char at from and to
		char temp = src[from];
		src[from] = src[to];
		src[to]   = temp;
		//move from and to
		from++;
		to--;
	}
}

/*
 * for a string src, move all the char on the left of pos to the end.
 */
bool rotateLeftPart(char* src, int pos, int size)
{
	if(pos >= size)
	{
		return false;
	}
	reverseString(src, 0, pos-1);
	reverseString(src, pos, size-1);
	reverseString(src, 0, size-1);
	return true;
}


int main()
{
	char src1[] = "abc hhd";
	char src2[] = "";
	char src3[] = "sefesfdjeewf";
	rotateLeftPart(src1, 3, 7);
	rotateLeftPart(src2, 3, 0);
	rotateLeftPart(src3, 3, 12);
	cout<<"src1 = "<<src1<<endl;
	cout<<"src2 = "<<src2<<endl;
	cout<<"src3 = "<<src3<<endl;

	return 0;

}





