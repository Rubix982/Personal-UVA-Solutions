// Consecutive Integers, use sum of arithmetic progression: n = r / 2 * ( 2 * a + r - 1 )
// or a = (2 x n + r - r ** 2)/ ( 2 x r ); as n is given, brute force all values
// of r from sqrt(2n) down to 1, stop at the first valid a
#include "../../../bits/stdc++.h"
using namespace std;

typedef long long int i64;

int main(void)
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, c= 1;
    cin >> t;

    while ( t-- )
    {
        int n, m, k;
        cin >> n >> m >> k;
        i64 sum = 0, a[n];
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
            sum += a[i];
        }

        i64 mean = sum / n;
        vector<i64> cakes, drinks;

        for ( int i = 0 ; i < m ; ++i ) cakes.emplace_back( a[i] );
        for ( int i = m ; i < m + k ; ++i ) drinks.emplace_back( a[i] );

        i64 A = a[n-1], B = a[n-1], minn_dist = a[n-1];
        for ( int i = 0; i < cakes.size() ; ++i ) 
        { 
            if ( minn_dist > abs(cakes[i] - mean) )
            {
                minn_dist = abs(cakes[i] - mean);
                A = cakes[i];
            }
        }

        minn_dist = a[n-1];
        for ( int i = 0; i < drinks.size() ; ++i ) 
        { 
            if ( minn_dist > abs(drinks[i] - mean) )
            {
                minn_dist = abs(drinks[i] - mean);
                B = drinks[i];
            }
        }

        cout << "Case #" << c << ": " << A << " " << B << "\n";
        ++c;
    }

    return 0;
}