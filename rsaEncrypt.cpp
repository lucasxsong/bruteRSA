#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>


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

// to compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// assumption is that m is prime

int gcd(int a, int m);

int modInverse(int a, int m) {
    if (gcd(a, m) != 1) {
        cout << "Inverse doesn't exist";
        return -1;
    }
    else {
        // if a and m are relatively prime, then modulo inverse is a^(m-2) 
        return power(a, m - 2, m);
    }
}

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } 
    else {
        return gcd(b, a % b);
    }
}

int power(int x, unsigned int y, unsigned int m) {
    if (y == 0) {
        return 1;
    }
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

// function to find private key from e and totient
int findPrivate(int e, int phi) {
    // e * x = phi * y + 1
    int eProd = e;
    int phiProd = phi + 1;
    int counter = 1;

    while (eProd != phiProd) { // in the case that e is lower than phi and needs to be incremented
        if (eProd < phiProd) {
            eProd += e;
            ++counter;
        }
        else {
            phiProd += phi;
        }
    }
    return counter;
}

int main() {
    cout << "welcome to RSA encryption services, inc" << endl;
    cout << "enter two distinct primes, p and q" << endl;
    int p, q;
    cin >> p >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1); // calculates totient function from p and q

    cout << "enter an e such that e is relatively prime to " << phi << endl;

    int e;
    cin >> e;

    cout << "public key is (" << e << "," << n << ")" << endl;
    
    int privateKey = findPrivate(e, phi); 

    cout << "private key is (" << privateKey << "," << n << ")" << endl;

    cout << "enter a message to encrypt" << endl;

    int message;
    cin >> message;

    int encrypted = Calculate(message, e, 1, n);

    cout << "encrypted message is " << encrypted << endl;

    int decrypted = Calculate(encrypted, e, 1, n);

    cout << "decrypted message is " << decrypted << endl;



    return 0;

}