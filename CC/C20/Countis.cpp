#include <iostream>

using namespace std;

int countis(int source, int i)
{
    if(i<1 || i>9)
    {
        return -1;  //0 is not ok, since no 01, 02....
    }

    int count = 0;
    int factor_10s = 1;
    int low=0, high=0, cur=0;

    while(source/factor_10s != 0)
    {
        low  = source - (source / factor_10s) * factor_10s;
        high = (source / factor_10s) / 10;
        cur  = (source / factor_10s) % 10;
    
        if(cur<i)
        {
            count += high * factor_10s;
        }
        else if(cur == i)
        {
            count += high * factor_10s + low + 1;
        }
        else
        {
            count += (high + 1) * factor_10s;
        }
        factor_10s *= 10;
    }
    return count;
}

int main()
{
    int input = 9923;
    cout<<input<<" has "<<countis(input, 2)<<" 2s."<<endl;

}

