// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876
#include "../../../bits/stdc++.h"
using namespace std;

int main(void)
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int rem;
    while ( scanf("%d", &n), n != 0)
    {
        list<int> l;
        vector<int> v;
        for ( int i = 0 ; i < n ; ++i ) l.push_back(i + 1);

        while ( l.size() > 1)
        {
            v.push_back(l.front());
            l.pop_front();

            l.push_back(l.front());
            l.pop_front();
        }

        cout << "Discarded cards: ";
        for ( int i = 0; i < v.size() - 1 ; ++i ) cout << v[i] << ", ";
        cout << v[v.size() - 1] << "\n";

        cout << "Remaining cards: " << l.front() << "\n";
    }

    return 0;
}