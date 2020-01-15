// Peter's Smoke, interesting simulation problem
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1287

/*

    SAMPLE INPUT DATA

    4 3
    10 3
    100 5

    SAMPLE OUTPUT DATA

    5
    14
    124

*/
#include "../../../bits/stdc++.h"
using namespace std;

int main(void)
{
    long long int n, k;
    while ( scanf("%ld%ld", &n, &k) == 2) printf("%ld\n", n + ( n - 1) / ( k - 1) );
    return 0;
}