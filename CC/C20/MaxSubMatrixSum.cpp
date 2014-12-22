#include <iostream>
#include <math.h>

using namespace std;

const int N = 10;

void preCompute(int sum[N][N], int source[N][N])
{
    sum[0][0] = source[0][0];
    for(int i=1; i<N; i++)
    {
        sum[i][0] = source[i][0] + sum[i-1][0];
        sum[0][i] = source[0][i] + sum[0][i-1];
    }
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + source[i][j];
        }
    }
}

int getMaxSubMatrixSum(int sum[N][N], int source[N][N])
{
    int maxSum = -9999;  // because matrix contains negative number
    for(int i=0; i<N; i++) // do not consider single element
    {
        for(int j=i; j<N; j++)
        {
            int curMax = 0;
            for(int k=0; k<N; k++)
            {
                int val = 0;
                if(k==0)
                {
                    val = sum[j][0] - sum[i][0] + source[i][0];
                }
                else
                {
                    val = sum[j][k] - sum[j][k-1] - sum[i][k] + sum[i][k-1] + source[i][k];
                }

                //for the max of this row
                if(curMax >= 0)
                {
                    curMax += val;
                }
                else
                {
                    curMax = val;
                }

                //for overall max
                if(curMax > maxSum)
                {
                    maxSum = curMax;
                }
            }
        }
    }
    return maxSum;
}

int main()
{
    int sum[N][N];
    int source[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            source[i][j] = i*j;
            source[i][j] *= pow(-1, i+j);
            cout<<source[i][j]<<", ";
        }
        cout<<endl;
    }

    preCompute(sum, source);
    cout<<"max sum = "<< getMaxSubMatrixSum(sum, source)<<endl;
}

