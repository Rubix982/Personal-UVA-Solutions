// Numbering Road ( simple math )
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2823

#include "../../../bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

/*
Test case

8 5
100 2
0 0
*/

int main(void)
{
    ull N, R;
    int test = 0;

    while ( scanf("%llu %llu", &R, &N) == 2 )
    {
        if ( N == 0 or R == 0 ) break;

        int ans = ( R - N ) / N + ( (R - N) % N != 0 and R >= N );
        printf( "Case: %d: ", ++test );
        if ( ans > 26 ) puts("impossible");
        else printf("%d\n", ans);
    }

    return 0;
}