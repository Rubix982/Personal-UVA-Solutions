// Back To Intermediate, several tricky test cases
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1714

#include "../../../bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;

/*
Test case

3
8 5 6
1 2 3
1 5 6
*/

int main(void)
{
    int t, i = 0;
    double d, v, u;
    cin >> t;
    
    while ( t-- )
    {
        cin >> d >> v >> u;
        double slowWay = (double)d / u, fastWay = (double)d / sqrt( u*u - v*v );
        if ( v >= u || fastWay == slowWay ) cout << "Case: " << ++i << ": can't determine\n";
        else printf("Case %d: %.3lf\n", ++i, fastWay - slowWay);
    }
    

    return 0;
}