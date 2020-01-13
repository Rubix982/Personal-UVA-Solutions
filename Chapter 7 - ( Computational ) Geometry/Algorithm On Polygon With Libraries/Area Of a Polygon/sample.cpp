#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

struct point { int x, y; point(int x, int y): x(x), y(y) {} };

bool isConvex(const vector<point> & p) 
{ 
    int sz = (int) p.size();
    if ( sz <= 3 ) return false;

    // What is ccw?
    bool isLeft = ccw(p[0], p[1], p[2]);
    
    for ( int i = 1; i < sz - 1; ++i )
        if ( ccw(p[i], p[i + 1], p[(i + 2) == sz ? 1 : i + 2 ]) != isLeft )
            return false;

    return true; 
}