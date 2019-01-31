#include <iostream>
#include <cmath>

using namespace std;

unsigned int power(unsigned int x, unsigned int y, unsigned int p) {
    unsigned int res = 1;
    x = x % p;

    while (y > 0) {
        if (y % 2 != 0) {
            res = (res * x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

unsigned int Calculate(unsigned int A, unsigned int B, unsigned int C, unsigned int M) {
    unsigned int res, ans;

    res = power(B, C, M-1);

    ans = power(A, res, M);

    return ans;
}

int main() {
    unsigned int A = 3, B = 9, C = 4, M = 19;

    cout << Calculate(A, B, C, M);

    return 0;
}

