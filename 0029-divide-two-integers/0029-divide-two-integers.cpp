class Solution {
public:

// logic we followed: Keep subtracting the largest doubled divisor until the number becomes smaller than the divisor.
    int divide(int dividend, int divisor) {

    // Overflow case
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long n = dividend;
    long long d = divisor;

    if(n < 0) n = -n;
    if(d < 0) d = -d;

    long long quotient = 0;

    while(n >= d) {

        long long temp = d;
        long long multiple = 1;

        while((temp << 1) <= n) {
            temp <<= 1;
            multiple <<= 1;
        }

        n -= temp;
        quotient += multiple;
    }

    if(negative)
        quotient = -quotient;

    return (int)quotient;
}

};