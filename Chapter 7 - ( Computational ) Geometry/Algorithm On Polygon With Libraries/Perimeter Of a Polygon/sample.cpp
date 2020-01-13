#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct point { int x, y; point(int x, int y): x(x), y(y) {} };

double perimeter(vector<point> &  p)
{
    double result = 0.0;

    for ( int i = 0 ; i < (int)p.size() - 1 ; ++i )
        result += distance(p.begin() + i, p.begin() + i + 1);
    return result;
}