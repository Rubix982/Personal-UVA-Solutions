#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

struct point { int x, y; point(int x, int y): x(x), y(y) {} };

double area ( const vector<point> &  p)
{
    double result = 0.0, x1, y1, x2, y2;

    for ( int i = 0 ; i < (int)p.size() - 1; ++i )
    {
        x1 = p[i].x; x2 = p[i+ 1].x;
        y1 = p[i].y; y2 = p[i+ 1].y;
        result += ( x1 * y2 - x2 * y1 );
    }

    return fabs(result) / 2.0;
}