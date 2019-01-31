// simple program to use fermats little theorem to find inverse of mod
//

#include <bits/stdc++.h>

using namespace std;
 
// to compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under mpdulo m
// assumption is that m is prime

void modInverse(int a, int m) {
    if (__gcd(a, m) != 1) {
        cout << "Inverse doesn't exist";
    }
    else {
        // if a and m are relatively prime, then modulo inverse is a^(m-2) 
        cout << "Modular multiplicative inverse is " << power(a, m - 2, m);
    }
}

int power(int x, unsigned int y, unsigned int m) P{
    if (y == 0) {
        return 1;
    }
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

int main() {
    cout << "enter a and m" << endl;
    int a, m;
    cin >> a >> m;
    modInverse(a, m);
    return 0;
}


