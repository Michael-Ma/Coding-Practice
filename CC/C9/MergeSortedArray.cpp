#include <iostream>

using namespace std;

void mergeArray(int A[], int sizeA, int B[], int sizeB)
{
    int posA = sizeA-1;
    int posB = sizeB-1;
    for(int i=sizeA+sizeB-1; i>=0; i--)
    {
        if(posA>=0 && posB>=0)
        {
            if(A[posA] > B[posB])
            {
                A[i] = A[posA];
                posA--;
            }else
            {
                A[i] = B[posB];
                posB--;
            }
        } else if(posA >= 0)
        {
            A[i] = A[posA];
            posA--;
        } else if(posB >= 0)
        {
            A[i] = B[posB];
            posB--;
        }
    }
}

int main()
{
    int A[15] = {1, 3, 4, 6, 7, 9, 12, 22, 32, 34};
    int B[5] = {2, 3, 8, 16, 79};
    mergeArray(A, 10, B, 5);
    for(int i=0; i<15; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

