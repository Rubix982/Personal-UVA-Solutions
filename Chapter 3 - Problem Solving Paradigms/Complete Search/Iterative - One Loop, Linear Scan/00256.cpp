#include "stdc++.h"
using namespace std;

/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192
*/

// Simple O(n^2) solution
// solution by rubix982

int n;

int main(void)
{
    while (scanf("%d", &n) != EOF)
        for (int i = 0; i < pow(10, n - 1) ; ++i)
            for (int j = 0; j < pow(10, n - 1); ++j)
                if ( pow(i + j, 2) == stoi(to_string(i) + to_string(j)) )
                    cout << i << j << "\n";

    return 0;
}