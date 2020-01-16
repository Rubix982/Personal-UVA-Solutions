// Bubble Sort, try small n; get the pattern, use long long
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3155
#include "../../../bits/stdc++.h"
using namespace std;

int findSwaps( int n, int a[] )
{
    int count = 0, i, j, temp, b[100000];
    for( i = 0; i < n; i++ ) b[i] = a[i];
    for( i = 0; i < n; i++ ) for( j = 0; j < n - 1; j++ ) if( b[j] > b[j+1] ) { swap(b[j], b[j+1]); count++; }
    return count;
}

int main(void)
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, c = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n ; ++i) a[i] = i + 1;
        shuffle(a, a + n, default_random_engine(0u));

        double sum = 0;
        for (int i = 0; i < n ; ++i ) sum += (double) findSwaps(i, a);

        cout << "Case " << c << ": " << " " << sum << " " << sum / n << "\n";
        ++c;
    }

    return 0;
}