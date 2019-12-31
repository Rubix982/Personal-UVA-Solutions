#include "stdc++.h"
using namespace std;

string f(int n)
{
    string str = "3.";
    int t = 10;
    while ( n-- )
    {
        str = str + to_string( t / 7 );
        t = t - 7 * (int)(t / 7), t *= 10;
    }
    return str;
}

int main(void)
{
    int n;
    cin >> n;
    cout << f(n) << "\n";

    return 0;
}