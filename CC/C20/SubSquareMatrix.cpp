#include <iostream>
#include <algorithm>

using namespace std;

static const int N = 30;

struct Square{
    int column, row, size;
};


bool isSquare(bool matrix[N][N], int col, int row, int size)
{
    for(int i=0; i<size; i++)
    {
        if(!matrix[row][col+i])
        {
            return false;
        }
        if(!matrix[row+i][col])
        {
            return false;
        }
        if(!matrix[row+size-1][col+i])
        {
            return false;
        }
        if(!matrix[row+i][col+size-1])
        {
            return false;
        }
    }
    return true;
}

Square getMaxSubSquare(bool matrix[N][N])
{
    int maxSize = 0;
    Square result;
    for(int col=0; col<N; col++)
    {
        if(maxSize >= N - col)
        {
            return result;
        }
        for(int row=0; row<N; row++)
        {
           int size = N - max(col, row);
           for(int size = N - max(col, row); size > maxSize; size--)
           {
                if(isSquare(matrix, col, row, size))
                {
                    maxSize       = size;
                    result.column = col;
                    result.row    = row;
                    result.size   = size;
                    break;
                }
           }
        }
    }
    return result;
}

int main()
{
    bool matrix[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            matrix[i][j] = true;
        }
    }
    for(int i=0; i<N; i++)
    {
        matrix[i][10] = false;
        matrix[i][22] = false;
    }

    Square sq = getMaxSubSquare(matrix);
    cout<<"col = "<<sq.column<<", row = "<<sq.row<<", size = "<<sq.size<<endl;
}
