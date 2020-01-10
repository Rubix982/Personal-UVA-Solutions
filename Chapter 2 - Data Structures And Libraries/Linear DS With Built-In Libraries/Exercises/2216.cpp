// Determine the median ( 50th percentile ) of S. 
// Assume that n is odd.

// Uses Median Of Medians, more info at,
// https://en.wikipedia.org/wiki/Median_of_medians

#include <iostream>
#include <cmath>
using namespace std;

#define ARR_SIZE 100

int select(int a[], int left, int right, int n);
int partition(int a[], int left, int right, int pivotIndex, int n);
int pivot(int a[], int left, int right);
int partition_5(int a[], int left, int right);

// Be careful to handle left, right and n
// when implementing. It's better to use the
// same index for left, right and n to avoid
// handle index converting.
int select(int a[], int left, int right, int n)
{
    while ( true )
    {
        if ( left == right ) return left;
        int pivotIndex = pivot(a, left, right);
        pivotIndex = partition(a, left, right, pivotIndex, n);

        if ( n == pivotIndex ) return n;
        else if ( n < pivotIndex ) right = pivotIndex - 1;
        else left = pivotIndex + 1;
    }
}

// There is a subroutine called partition that can, in linear 
// time, group a list (ranging from indices left to right) 
// into three parts, those less than a certain element, those 
// equal to it, and those greater than the element (a three-way partition). 
// The grouping into three parts ensures that the median-of-medians 
// maintains linear execution time in a case of many or all 
// coincident elements. Here is pseudocode that performs a 
// partition about the element list[pivotIndex]:
int partition(int a[], int left, int right, int pivotIndex, int n) {
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[right]);
    int storeIndex = left;

    // Move all elements smaller than the pivot to the left of the pivot
    for ( int i = left ; i < right ; ++i )
    {
        if ( a[i] < pivotValue ) 
        {
            swap(a[storeIndex], a[i]);
            storeIndex++;
        } 
    }

    // Move all elements equal to the pivot right after
    // the smaller elements
    int storeIndexEq = storeIndex;
    for ( int i = storeIndex ; i < right ; ++i )
    {
        if ( a[i] == pivotValue )
        {
            swap(a[storeIndexEq], a[i]);
            storeIndexEq++;
        }
    }

    // Move pivot to its final place
    swap(a[right], a[storeIndexEq]);

    // Return location of pivot considering the desired location n
    if ( n < storeIndex ) 
        return storeIndex;  // n is in the group of smaller elements

    if ( n <= storeIndexEq ) 
        return n;           // n is the group equal to pivot

    return storeIndexEq;    // n is in the group of larger elements
}

// Subroutine pivot is the actual median-of-medians algorithm. 
// It divides its input (a list of length n) into groups of at most
//  five elements, computes the median of each of those groups using 
// some subroutine, then recursively computes the true median of the 
// n/5 medians found in the previous step : 
// [1].Note that pivot calls select this is an instance of mutual recursion. 
int pivot(int a[], int left, int right)
{
    // for 5 or less elements just get median
    if ( right - left < 5 ) return partition_5(a, left, right);

    // Otherwise move the medians of the five-element subgroups to the first n/5 positions

    for ( int i = left; i < right; i += 5 )
    {
        // get the median position of the i'th five-element subgroup
        int subRight = i + 4;
        if ( subRight > right ) subRight = right;
        int median_5 = partition_5(a, i, subRight);
        swap(a[median_5], a[ left + (int)floor((i - left)/5)]);
    }

    // Computer the median of the n/5 medians-of-five
    int mid = (right - left) / 10 + left + 1;
    return select(a, left, left + floor((right - left) / 5), mid); 
}

// The partition5 subroutine selects the median of a group of 
// at most five elements; an easy way to implement this is 
// insertion sort, as shown below.[1] It can also be 
// implemented as a decision tree.
int partition_5(int a[], int left, int right)
{
    int i = left + 1;

    while ( i <= right )
    {
        int j = i;
        while ( j > left && a[j - 1] > a[j] )
        {
            swap(a[j - 1], a[j]);
            j--;
            i++;
        }
    }

    return floor((left + right) / 2);
}

int main(void)
{    
    int arr[ARR_SIZE]{0};

    return 0;
}

// The above is the implementation for the below pseudo-code
// function select(list, left, right, n)
//     loop
//         if left = right then
//              return left
//         pivotIndex := pivot(list, left, right)
//         pivotIndex := partition(list, left, right, pivotIndex, n)
//         if n = pivotIndex then
//             return n
//         else if n < pivotIndex then
//             right := pivotIndex − 1
//         else
//             left := pivotIndex + 1

// < ---------------------------------------------------------------------------------->

// The above is based on the pseudo-code:
//  function partition(list, left, right, pivotIndex, n)
//      pivotValue := list[pivotIndex]
//      swap list[pivotIndex] and list[right]  // Move pivot to end
//      storeIndex := left
//         Move all elements smaller than the pivot to the left of the pivot
//      for i from left to right − 1 do
//          if list[i] < pivotValue then
//              swap list[storeIndex] and list[i]
//              increment storeIndex
//         Move all elements equal to the pivot right after
//         the smaller elements
//      storeIndexEq = storeIndex
//      for i from storeIndex to right − 1 do
//          if list[i] = pivotValue then
//              swap list[storeIndexEq] and list[i]
//              increment storeIndexEq
//      swap list[right] and list[storeIndexEq]  // Move pivot to its final place
//         Return location of pivot considering the desired location n
//      if n < storeIndex then
//          return storeIndex  // n is in the group of smaller elements
//      if n ≤ storeIndexEq then
//          return n  // n is in the group equal to pivot
//      return storeIndexEq // n is in the group of larger elements

// < ---------------------------------------------------------------------------------->

//   function pivot(list, left, right)
//         for 5 or less elements just get median
//      if right − left < 5 then
//          return partition5(list, left, right)
//         otherwise move the medians of five-element subgroups to the first n/5 positions
//      for i from left to right in steps of 5
//             get the median position of the i'th five-element subgroup
//          subRight := i + 4
//          if subRight > right then
//              subRight := right
//          median5 := partition5(list, i, subRight)
//          swap list[median5] and list[left + floor((i − left)/5)]

//         compute the median of the n/5 medians-of-five
//      mid := (right − left) / 10 + left + 1
//      return select(list, left, left + floor((right − left) / 5), mid)

// < ---------------------------------------------------------------------------------->

//  function partition5( list, left, right)
//      i := left + 1
//      n while i ≤ right
//          j := i
//          while j > left and list[j−1] > list[j] do
//              swap list[j−1] and list[j]
//              j := j − 1
//          i :=  i + 1
            
//      return floor((left + right) / 2)