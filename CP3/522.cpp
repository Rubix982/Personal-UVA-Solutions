#include "stdc++.h"
using namespace std;

// Gives back the number of digits in O(1) time

int main(void) {

    std::cout << "<------- START ------->" << "\n";
    for (int i = 1; i <= 50000; ++i) std::cout << (int) floor( 1 + log10( (double) i ) ) << " " << i << "\n";

    return 0;
}