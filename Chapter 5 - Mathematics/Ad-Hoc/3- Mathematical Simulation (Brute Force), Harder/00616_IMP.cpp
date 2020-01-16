// Coconuts, Revisited, brute force upto sqrt(n), get pattern
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=557

#include "../../..//bits/stdc++.h"
using namespace std;
typedef long long int lli;

int main(void)
{
    lli n;

    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ( scanf("%lld", &n) == 1, n >= 0 )
    {
        if ( n == 0 ) { cout << "0 coconuts, no solution\n"; }

        int i = 9 ;
        for ( ; i > 1; --i )
        {
            lli tmp = n;

            int j = 0;
            for ( ; j < i ; ++j )
            {
                tmp--;

                if ( tmp % i != 0 ) break;

                tmp = tmp - ( tmp / i );
            }

            if ( i == j and tmp % i == 0 ) { cout << n << " coconuts, " << j << " people and 1 monkey\n"; break; }
        }

        if ( i == 1 ) cout << n << " coconuts, no solution\n";
    }
    return 0;
}