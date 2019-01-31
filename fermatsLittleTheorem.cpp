// simple program to use fermats little theorem to find inverse of mod
//

//#include <bits>
#include <iostream>
#include <algorithm>
#include <numeric> 

using namespace std;
 
// to compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// assumption is that m is prime

int gcd(int a, int m);

void modInverse(int a, int m) {
    if (gcd(a, m) != 1) {
        cout << "Inverse doesn't exist";
    }
    else {
        // if a and m are relatively prime, then modulo inverse is a^(m-2) 
        cout << "Modular multiplicative inverse is " << power(a, m - 2, m);
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

int main() {
    int input = 1;
    while (input != 0) {
        cout << "enter 1 for fermats, 2 for gcd, 0 to quit" << endl;
        cin >> input;
        if (input == 1) {
            cout << "enter a and m" << endl;
            int a, m;
            cin >> a >> m;
            modInverse(a, m);
        }
        if (input == 2) {
            cout << "enter two numbers to find gcd" << endl;
            int a, b;
            cin >> a >> b;
            cout << gcd(a, b) << endl;
        }
        
    }

    
    return 0;
}


