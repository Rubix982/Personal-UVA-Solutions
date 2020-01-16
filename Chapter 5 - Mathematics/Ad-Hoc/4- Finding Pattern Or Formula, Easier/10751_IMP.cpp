// Chessboard, trival for N = 1, and N = 2; drive the formula first for N > 2; hint, use diagonal as much as possible
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1692
#include "../../../bits/stdc++.h"
using namespace std;

int main(void)
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        cout << n << "\n";
        if ( n == 1 ) cout << "0.000\n\n";
        else if ( n == 2 ) cout << "4.000\n\n";
        else 
        {

                // Can't figure it out. :/

        }

    }

    return 0;
}