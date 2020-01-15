#include "../../bits/stdc++.h"
using namespace std;

#define DIM 15
char board[DIM][DIM];
int ans = 0;

void backtract(int c)
{
    if ( c == DIM ) { ans++; return; }
    else
    {
        for ( int i = 0; i < DIM; i++ )
            if ( board[r][c] != '*' and )
    }
}

int main(int argc, char const *argv[])
{
    for ( int i = 0 ; i < DIM ; ++i )
        for ( int j = 0 ; j < DIM ; ++j )
            board[i][j] = ' ';

    for ( int i = 0 ; i < 8 ; ++i)
        backtract(i)

    return 0;
}