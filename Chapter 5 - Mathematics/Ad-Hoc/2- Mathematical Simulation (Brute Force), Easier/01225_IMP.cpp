// Digit Counting, LA 3996, Danang07, N is small
#include "../../../bits/stdc++.h"
using namespace std;

int main()
{

    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while ( n-- )
    {
        int t;
        cin >> t;
        int freq[10]{0};

        for ( int i = 1 ; i <= t ; ++i )
        {
            int val = i;
            while ( val > 0 )
            {
                freq[val % 10]++;
                val /= 10;
            }
        }
        for ( int i = 0 ; i < 10 ; ++i ) cout << freq[i] << " ";
        cout << "\n";

    }

    return 0;
}