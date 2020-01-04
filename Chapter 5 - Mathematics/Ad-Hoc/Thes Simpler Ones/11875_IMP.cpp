// Brick Game ( get median of a sorted input )
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2986

#include "../../../bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long double ld;

/*

Sample Input

2
5 19 17 16 14 12
5 12 14 16 17 18

*/

/*

Sample Output

Case 1: 16
Case 2: 16

*/

int main(void)
{
    int t, s;
    int test = 0;
    scanf("%d", &t);

    while ( t-- ) 
    {
        scanf("%d", &s);
        int a[s];
        for ( int i = 0 ; i < s ; ++i ) scanf("%d", &a[i]);

        sort(a, a + s);
        printf( "Case %d: %d\n", ++test, a[s/2] );
    }

    return 0;
}