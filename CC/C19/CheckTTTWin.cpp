#include <iostream>

using namespace std;

enum Piece { EMPTY, BLUE, RED };
enum Check { ROW, COLUMN, DIAGONAL, REDIAGONAL };

const int N = 3;

Piece getPosColor(Piece board[N][N], int fixIndex, int varIndex, Check type)
{
    if(type == ROW)
    {
        return board[fixIndex][varIndex];
    }
    else if(type == COLUMN)
    {
        return board[varIndex][fixIndex];
    }
    else if(type == DIAGONAL)
    {
        return board[varIndex][varIndex];
    }
    else if(type == REDIAGONAL)
    {
        return board[varIndex][N-1-varIndex];
    }
    return EMPTY;
}

//check whether there is a winner exist when considering this index
Piece checkWinner(Piece board[N][N], int fixIndex, Check type)
{
    Piece color = getPosColor(board, fixIndex, 0, type);
    if(color == EMPTY)
    {
        return EMPTY;
    }
    for(int i=1; i<N; i++)
    {
        Piece nextColor = getPosColor(board, fixIndex, i, type);
        if(color != nextColor)
        {
            return EMPTY;
        }
    }
    return color;
}

Piece hasWon(Piece board[N][N])
{
    Piece winner = EMPTY;
    //for row and column we need to check 3 X 3 times
    for(int i=0; i<N; i++)
    {
        winner = checkWinner(board, i, ROW);
        if(winner != EMPTY)
        {
            return winner;
        }

        winner = checkWinner(board, i, COLUMN);
        if(winner != EMPTY)
        {
            return winner;
        }
    }

    winner = checkWinner(board, -1, DIAGONAL);
    if(winner != EMPTY)
    {
        return winner;
    }

    winner = checkWinner(board, -1, REDIAGONAL);
    if(winner != EMPTY)
    {
        return winner;
    }
    return winner;
}


int main()
{
    Piece board[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i == j)
            {
                board[i][j] = BLUE;
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
    cout<<"Winner is "<<hasWon(board)<<endl;
}
