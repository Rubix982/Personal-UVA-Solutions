#include "stdc++.h"
using namespace std;

#define SIZE 14
bitset<30> rw, ld, rd;
int ans = 0, maxx = -1, board[SIZE][SIZE];

void print_board()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "\n";
}

void backtrack(int c)
{
    if ( c == 8 ) { 
        if ( maxx < ans) maxx = ans; 
        return; 
    }

    for ( int r = 0 ; r < 8 ; ++r )
    {
        if ( board[r][c] != '*' and !rw[r] and !ld[r - c + 8 - 1] and !rd[r + c] )
        {
            rw[r] = ld[r - c + 8 - 1] = rd[r + c] = true;
            ans += board[r][c];
            backtrack(c + 1);
            ans -= board[r][c];
            rw[r] = ld[r - c + 8 - 1] = rd[r + c] = false;
        }
    }
}
    
int main(void)
{
    int t, s = 0;
    cin >> t;

    while ( t-- )
    {
        for ( int i = 0 ; i < 8 ; ++i )
            for ( int j = 0 ; j < 8 ; ++j )
                cin >> board[i][j];

        backtrack(0);
        
        cout << maxx << "\n";
    }

    return 0;
}