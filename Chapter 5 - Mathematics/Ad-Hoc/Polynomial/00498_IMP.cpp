// Polly The Polynomial, polynomial evaluation
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=439

/* 
    SAMPLE INPUT 
    -2
    5 0 1 6
    1 -1
    7 6 -1

    SAMPLE OUTPUT
    -2 -2 -2 -2
    6 5 -2

*/

#include "../../../bits/stdc++.h"
using namespace std;

void fastscan(int & number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if ( c == '-' )
    {
        negative = true;
        c = getchar();
    }

    for ( ; ( c > 47 and c < 58 ) ; c = getchar() ) number = number * 10 + c - 48;
    if (negative) number *= -1;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int num;

    while ( getline(cin, line) )
    {
        stringstream ss(line);
        vector<int> polynomial;
        vector<int> questions;

        while ( ss >> num ) polynomial.push_back(num);

        getline(cin, line);
        ss.clear();
        ss.str(line);

        while ( ss >> num ) questions.push_back(num);

        for ( int i = 0 ; i < questions.size() ; ++i )
        {
            int sum = 0;
            for ( int j = 0; j < polynomial.size() ; ++j )
                sum += polynomial[j] * pow(questions[i], j);

            cout << sum << " ";
        }

        cout << "\n";
    }

    return 0;
}