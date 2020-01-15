// Perfection, do trial division

/* 
https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=318
*/

/*

    SAMPLE INPUT DATA

    15 28 6 56 60000 22 496 0

    SAMPLE OUTPUT DATA

    PERFECTION OUTPUT
        15  DEFICIENT
        28  PERFECT
         6  PERFECT
        56  ABUNDANT
     60000  ABUNDANT
        22  DEFICIENT
        496 PERFECT
    END OF OUTPUT

*/

#include "../../../bits/stdc++.h"
using namespace std;

int outputs(int a)
{
    int sum = 0;
    for ( int i = 1 ; i < a / 2 + 1 ; ++i ) if ( a % i == 0 ) sum += i;
    return sum;
}

int main(void)
{
    ifstream infile("in.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(infile, str);
    stringstream ss(str);
    vector<int> v;

    int max_digit = 0;
    int tmp; while ( ss >> tmp ) {max_digit = max(max_digit, (int)floor(1 + log10((double)tmp))); v.emplace_back(tmp);}
    cout << "PERFECTION OUTPUT\n";

    v.shrink_to_fit();

    for ( int i = 0; i < v.size() - 1; ++i )
    {
        cout << setw(max_digit) << right << v[i] << "  ";

        if ( v[i] >= 1 and v[i] <= 5 )
        {
            cout << "DEFICIENT\n";
            continue;
        } 

        int value = outputs(v[i]);

        if ( value > v[i] ) cout << "ABUNDANT\n";
        else if ( value < v[i] ) cout << "DEFICIENT\n";
        else cout << "PERFECT\n";
    }

    cout << "END OF OUTPUT\n";


    return 0;
}