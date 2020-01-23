#include "stdc++.h"
using namespace std;

int main(void)
{

    int t;
    scanf("%d", &t);

    while ( t-- )
    {
        long long n, an = 0, d, k;
        scanf("%lld", &n);
        int arr[n + 1];

        for ( int i = 0 ; i <= n ; ++i ) scanf("%d", &arr[i]);
        scanf("%lld %lld", &d, &k);
        
        for ( int i = 0 ; i <= n ; ++i ) an += arr[i]*pow(n, i);
        long long ao = an - ( n - 1 ) * d;

        cout << an << " " << ao << "\n";
        cout << (k * ( 2 * ao + ( k - 1) * d)) / 2 << "\n";

    }

    return 0;
}