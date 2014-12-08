#include <iostream>
#include <cstdlib>

using namespace std;

// generate random bum between low and high
// not including high and low
int getRand(int low, int high)
{
    if(low >= high)
    {
        return -1;  //error code
    }
    return rand()%(high-low) + low;
}

void perfectShuffle(int input[], int size)
{
    for(int i=0; i<size; i++)
    {
        int random = getRand(i, size);
        swap(input[i], input[random]);
    }
}

int main()
{
    int input[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    perfectShuffle(input, 9);
    for(int i=0; i<9; i++)
    {
        cout<<input[i]<<", ";
    }
    cout<<endl;
}

