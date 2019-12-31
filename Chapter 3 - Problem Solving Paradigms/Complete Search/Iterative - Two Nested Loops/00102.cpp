#include "stdc++.h"
using namespace std;

/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=38

Extremely trivial solution - hey, it works! Note that only 6 permutations are possible, so just hard code the results
*/

long C[3]{0}, B[3]{0}, G[3]{0};

/*
    CBG
    CGB
    GBC
    GCB
    BCG
    BGC    
*/

int main(void)
{
    while (scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld", &B[0], &G[0], &C[0], &B[1], 
        &G[1], &C[1], &B[2], &G[2], &C[2]) != EOF) {

            long minn = INT32_MAX, temp;
            char ans[4];

            // BCG
            temp = (C[0] + G[0]) + (B[1] + G[1]) + (B[2] + C[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "BCG");
            }

            // BGC
            temp = (C[0] + G[0]) + (C[1] + B[1]) + (B[2] + G[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "BGC");
            }

            // CBG
            temp = (B[0] + G[0]) + (C[1] + G[1]) + (B[2] + C[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "CBG");
            }

            // CGB
            temp = (B[0] + G[0]) + (C[1] + B[1]) + (G[2] + C[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "CGB");
            }

            // GCB
            temp = (B[0] + C[0]) + (B[1] + G[1]) + (G[2] + C[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "GCB");
            }

            // GBC
            temp = (B[0] + C[0]) + (C[1] + G[1]) + (B[2] + G[2]);
            if (temp < minn)
            {
                minn = temp;
                strcpy(ans, "GBC");
            }

            printf("%s %d\n", ans, minn);
        }

        return 0;
}