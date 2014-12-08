#include <iostream>

using namespace std;

const unsigned N = 4;

struct Result
{
    int hits;
    int pseudoHits;

    Result(): hits(0), pseudoHits(0){}
};

Result checkColorHit(char guess[N+1], char solution[N+1])
{
    Result result;
    int mask = 0;

    // setup bitmap
    for(int i=0; i<N; i++)
    {
        mask |= 1 << (1 + solution[i] - 'A');  // incase A is used, will need to set 1 for it.
    }

    // calculate bits andpseudoHits
    for(int i=0; i<N; i++)
    {
        if(guess[i] == solution[i])
        {
            result.hits++;
        }
        else
        {
            if((mask & 1<<(1 + guess[i] - 'A')) > 0)
            {
                result.pseudoHits++;
            }
        }
    }

    return result;
}


int main()
{
    char guess1[N+1] = "RYGG";
    char guess2[N+1] = "GGGG";
    char guess3[N+1] = "RYBG";
    char solution[N+1] = "RYGG";
    Result r1 = checkColorHit(guess1, solution);
    Result r2 = checkColorHit(guess2, solution);
    Result r3 = checkColorHit(guess3, solution);
    cout<<"guess 1 : hits = "<<r1.hits<<", pseudoHits = "<<r1.pseudoHits<<endl;
    cout<<"guess 2 : hits = "<<r2.hits<<", pseudoHits = "<<r2.pseudoHits<<endl;
    cout<<"guess 3 : hits = "<<r3.hits<<", pseudoHits = "<<r3.pseudoHits<<endl;
}

