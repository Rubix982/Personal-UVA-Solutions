// Throwing Cards Away II, find pattern with brute force

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
        for ( int i = 0 ; i < n ; ++i ) l.push_back(i + 1);

        while ( l.size() > 1)
        {
            l.pop_front();
            l.push_back(l.front());
            l.pop_front();
        }

        cout << l.front() << "\n";
    }
    
    return 0;
}