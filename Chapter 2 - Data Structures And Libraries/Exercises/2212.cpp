// Find an integer v, find two integers a, b belong to S, such that a + b = v

#include "../../bits/stdc++.h"
using namespace std;

#define ARR_SIZE 20

bool binary_search(int a[], int key, int n)
{
    int low = ARR_SIZE / 2 + 1, high = n;

    while ( low < high )
    {
        int mid = ( low + high ) / 2;
        if ( a[mid] == key ) return true;
        else if ( a[mid] < key ) low = mid + 1;
        else if ( a[mid] > key ) high = mid - 1;
    }

    return false;
}

void merge(int a[], int p, int q, int n)
{
    int n1 = q - p + 1, i, j, k, n2 = n - q, l[n1], r[n2];
    for ( i = 0 ; i < n1 ; ++i ) l[i] = a[p + i];
    for ( j = 0 ; j < n2 ; ++j ) r[j] = a[q + j + 1]; 
    j = 0, i = 0;
    for ( k = p ; i < n1 and j < n2 ; ++k ) l[i] < r[j] ? a[k] = l[i++] : a[k] = r[j++];
    while ( i < n1 ) a[k++] = l[i++];
    while ( j < n2 ) a[k++] = r[j++];
}

void mergeSort(int a[], int p, int n)
{
    if ( p < n) 
    {
        int q = ( p + n ) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, n);
        merge(a, p, q, n);
    }
}

int main(void)
{
    srand(time(NULL));

    int a[ARR_SIZE]{0};
    for ( int i = 0 ; i < ARR_SIZE ; ++i ) a[i] = 1 + ( rand() % 500 );
    mergeSort(a, 0, ARR_SIZE - 1);

    // FIND SUM OF THIS NUMBER
    int v = 1 + ( rand() % ARR_SIZE - 1);

    bool flag = false;
    for ( int i = 0; i < ARR_SIZE / 2 ; ++i ) if (binary_search(a, v - a[i], ARR_SIZE )) { flag = true; break; }

    flag ? (cout << "YES") : (cout << "NO");

    for ( int i = 0; i < ARR_SIZE ; ++i ) cout << a[i] << " ";

    return 0;
}