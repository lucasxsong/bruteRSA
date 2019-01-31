#include <iostream>
#include <cmath>

using namespace std;

unsigned int power(unsigned int x, unsigned int y, unsigned int p) {
    unsigned int res = 1;
    x = x % p; // update x is it is more than or equal to p

    while (y > 0) {
        if (y % 2 != 0) {
            // if y is odd, multiply x with the result
            res = (res * x) % p;
        }
        // y must be even
        y = y>>1; // y = y / 2 
        x = (x*x) % p;
    }
    return res;
}

unsigned int Calculate(unsigned int A, unsigned int B, unsigned int C, unsigned int M) {
    unsigned int res, ans;
    // calculate B ^ C(mod M - 1)
    res = power(B, C, M-1);

    // calculate A ^ res (mod M )
    ans = power(A, res, M);

    return ans;
}

int main() {
    unsigned int A = 32, B = 29, C = 1, M = 91;

    cout << Calculate(A, B, C, M);

    return 0;
}

