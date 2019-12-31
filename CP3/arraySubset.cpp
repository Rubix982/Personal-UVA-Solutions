#include "stdc++.h"
using namespace std;

typedef vector<int> vi;

int main(void)
{
    vi v;
    int n, requiredSum;
    bool flag = false;
    cin >> n >> requiredSum;

    int a[n];
    for ( int i = 0; i < n ; ++i ) cin >> a[i];

    for ( int i = 0; i < (1 << n) ; ++i )
    {
        int sum = 0;
        for ( int j = 0 ; j < n ; ++j ) 
        {
            if ( ( i & ( 1 << j)) > 0 ) 
            {

                int s = (i & (1 << j)), t = 0;

                while ( s != 1 )
                {
                    s >>= 1;
                    ++t;
                }

                sum += a[t];
                v.push_back(a[t]);
            }
        }
        
        if ( sum == requiredSum ) 
        {
            flag = true;

            for ( const auto & value : v ) cout << value << " ";

            break;
        }

        v.clear();

    }

    if ( !flag ) cout << "NO\n";

    return 0;
}