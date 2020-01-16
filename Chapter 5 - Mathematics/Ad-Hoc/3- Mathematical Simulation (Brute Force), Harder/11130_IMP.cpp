// Billiard Bounces, use billiad table reflection technique: 
// mirror the billiard table to the right ( and/or top ) so that we will 
// only deal with one straight line instead of the bouncing lines
#include "../../../bits/stdc++.h"
using namespace std;

typedef long long int lli;

int main(void)
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const double pi = acos(-1);
    double a, b, v, A, s;
    while ( scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &s) == 5, a != 0 and b != 0 )
    {
        double L = s * v / 2;
        double H = L * cos( A / 180 * pi );
        double W = L * sin( A / 180 * pi );
        printf("%.0lf %.0lf\n", H / a, W / b);
    }

    return 0;
}