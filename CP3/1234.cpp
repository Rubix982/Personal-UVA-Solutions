#include "stdc++.h"
using namespace std;

int main(void)
{

    int n, freq[10]{0};
    cin >> n;

    for ( int i = 0; i < n ; ++i )
    {
        int tmp;
        cin >> tmp;
        freq[tmp]++;
    }

    for ( int i = 0; i < 10 ; ++i )
        if ( freq[i] >= 1 )
            std::cout << i << " ";
    
    cout << "\n";

    return 0;
}