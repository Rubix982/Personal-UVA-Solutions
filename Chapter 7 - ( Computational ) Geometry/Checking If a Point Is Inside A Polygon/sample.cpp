#include <cmath>
#include <vector>
using namespace std;

struct point { int x, y; point(int x, int y): x(x), y(y) {} };

bool inPolygon(point pt, const vector<point> & p )
{
    if ((int)p.size() == 0 ) return false;

    double sum = 0;

    for ( int i = 0; i < (int)p.size() - 1; ++i )
        if ( ccw(pt, p[i], p[i+1])) sum += angle(p[i], pt, p[i+1]);
        else sum -= angle(p[i], pt, p[i+1]);

    return fabs(fabs(sum) - 2 * PI ) < EPS;
}