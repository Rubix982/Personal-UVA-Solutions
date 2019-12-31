    #include <iostream>
    using namespace std;

    /* 
    Find nth root of a value a, Code from 
    https://www.quora.com/How-do-I-write-a-program-in-C-that-will-compute-the-nth-root-of-a-number-by-using-a-numerical-approximation-Newtons-Method-Calculations-must-be-based-on-just-square-and-or-cubic-roots
    */

    double root ( double a, int n );
    double IntPowFast( double x, int n );
    double IntPow( double x, int n );

    int main(void) {

        double a;
        int n;
        std::cout << "Enter value (positive) and nth root: ";
        cin >> a >> n;

        std::cout << n << "th root of " << a << " is " << root(a, n) << "\n";

        return 0;
    }

    // * Non-recursive function, uses Newton's method to calculate 
    // * Nth root for A
    double root(double a, int n) {

        const double eps = 1e-14;                               // ? A constant for the change in the fractional values ...
        double x = a;                                           // ? ... consider the value entered as 'x' ...
        while ( true ) {                                        // ? ... run an infinite loop until a value is returned to func main() ...
            double x0 = x;                                      // ? ... consider the original value of 'x', and save it in x0 ...
            double factor = (x - a * IntPowFast(x, 1 - n)) / n; // ? ... get back a factor using IntPowFast, notice 1 - n, and not n - 1
            x = x - factor;                                     // ? ... subtract from x a difference caused by the factor
            if ( fabsl(x - x0) <= fabsl(eps * x0) ) return x;   // ? ... return iff the difference becomes smaller than the original value times eps
        }
    }

    // * Simply return an even number depending on the number of 
    // * bits turned on in the number 'n' 
    double IntPowFast(double x, int n) {

        if ( n < 0 ) {
            x = 1.0 / x;                                        // ? return to x it's multiplicative inverse
            n = -n; }                                           // ? Invert n's sign
        int bit = -1;                                           // ? Starting from -1 ...
        for ( int temp = n ; temp > 0 ; temp >>= 1 ) bit++;     // ? ... Find out the number of bits in the number 'n'
        double r = 1.0;                                         // ? ... now make a recurrent 'r' variable, setting it to 1.0 ...
        for ( ; bit >= 0 ; bit--, r *= r )                      // ? ... then starting count to 0, squaring 'r' everytime ...
            if ((( n >> bit) & 1) != 0) r *= x;                 // ? ... if the bits of n shifted result in an odd number, multiply r by x, return to r ...
        return r;                                               // ? ... now return r ...
    }

    // * Try to balance off the value for 'r', by adjusting it with x
    double IntPow(double x, int n) {
        double r = 1.0;
        if ( n >= 0 )   for ( ; n > 0 ; n-- ) r *= x;
        else            for ( ; n < 0 ; n++ ) r /= x;
        return r;
    }