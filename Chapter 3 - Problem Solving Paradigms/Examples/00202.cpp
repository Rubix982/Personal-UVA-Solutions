/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=138
*/

#include "stdc++.h"
using namespace std;
typedef unsigned long long ull;

string getDec(int n, int d)
{
    int r = 10 * ( n - (int)( n / d) * d );

    for ( ull i = 0 ; i <= 3000 ; i << 1)
    {
        r *= 10;
        if ( r >= d )
        {
            
        }
    }
}

int main(void)
{
    int t ;

    cin >> t;

    while ( t-- )
    {
        int n, d;
        cin >> n >> d;

        if ( n % d == 0 ) 
        {
            cout << n << "/" << d << n / d << ".(0)\n\t 3000 = number of digits in repeating cycle.\n";
        }
        else
        {
            string str = getDec(n, d);
        }
    }

    return 0;
}