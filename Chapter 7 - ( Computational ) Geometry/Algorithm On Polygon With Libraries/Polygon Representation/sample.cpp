#include <vector>
using namespace std;

struct point { int x, y;
    point(int x, int y) : x(x), y(y) {}
};

int main(void)
{
    vector<point> vect;
    vect.emplace_back(point(1, 1));
    vect.emplace_back(point(3, 3));
    vect.emplace_back(point(9, 1));
    vect.emplace_back(point(12, 4));
    vect.emplace_back(point(9, 7));
    vect.emplace_back(point(1, 7));
    vect.push_back(vect[0]);            // Important loop back

    return 0;
}