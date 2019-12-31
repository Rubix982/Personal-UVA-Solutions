#include "stdc++.h"
using namespace std;

typedef tuple<int,int,int> tii;
typedef vector<tii> vtiii;

int main(void)
{
    vtiii v;

    int n;
    cin >> n;
    for ( int i = 0 ; i < n ; ++i )
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(a, b, c));
    }

    sort(v.begin(), v.end(), [](const tii & lhs, const tii & rhs) {
        return  ( get<2>(lhs) < get<2>(rhs)) || 
                ( get<2>(lhs) == get<2>(rhs) and get<1>(lhs) < get<1>(rhs) ) ||
                ( get<2>(lhs) == get<2>(rhs) and get<1>(lhs) == get<1>(rhs) and get<0>(lhs) < get<0>(rhs) );
    });

    cout << "\n\n\n";
    for (const auto &obj : v)
        cout << get<0>(obj) << " " << get<1>(obj) << " " << get<2>(obj) << "\n";

    return 0;
}