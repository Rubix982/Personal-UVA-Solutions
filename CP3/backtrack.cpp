#include "stdc++.h"
using namespace std;

#define SIZE 1000
int ans = 0, a, b, row[8]{0};

bool place(int i, int j)
{
    for ( int prev = 0 ; prev < c ; ++prev )
        if ( row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    return true;    
}

void backtrack(int c)
{
    for ( int r = 0 ; r < 8 ; ++r )
        if ( place(r, c)) {
            row[c] = r; backtrack(c + 1);
        }
}

int main(void)
{
    backtrack(0);
    return 0;
}