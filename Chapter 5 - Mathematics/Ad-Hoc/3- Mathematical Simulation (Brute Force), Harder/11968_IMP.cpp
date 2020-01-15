// Consecutive Integers, use sum of arithmetic progression: n = r / 2 * ( 2 * a + r - 1 )
// or a = (2 x n + r - r ** 2)/ ( 2 x r ); as n is given, brute force all values
// of r from sqrt(2n) down to 1, stop at the first valid a