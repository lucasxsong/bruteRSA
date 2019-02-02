#include <iostream>


using namespace std;

int power(int x, unsigned int y, unsigned int m);

unsigned int Calculate(unsigned int A, unsigned int B, unsigned int C, unsigned int M) {
    unsigned int res, ans;
    // calculate B ^ C(mod M - 1)
    res = power(B, C, M-1);

    // calculate A ^ res (mod M )
    ans = power(A, res, M);

    return ans;
}

int power(int x, unsigned int y, unsigned int m) {
    if (y == 0) {
        return 1;
    }
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

int main() {
    int e;
    int d;
    int n;
    int c;

    cout << "enter public key (e, n)" << endl;
    cin >> e >> n;

    cout << "enter private key (d)" << endl;
    cin >> d;

    cout << "enter encrypted message" << endl;
    cin >> c;
    int decrypted = Calculate(c, d, 1, n);

    cout << "decrypted message is " << decrypted << endl;

    return 0;
}