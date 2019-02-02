#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    // initializing int, char map for decoding
    map<int, char> intToChar;

    intToChar['2'] = 'a';
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
    
    for(int i = 2; i != 29; ++i) {
        intToChar[i] = a[i - 2];
    }

    string f;
    string o;
    cout << "enter file to translate" << endl;
    cin >> f;
    cout << "enter file to output to" << endl;
    cin >> o;

    ifstream inputFile;
    ofstream outputFile(o);

    inputFile.open(f);

    // take in int and return a file of strings
    while(!inputFile.eof()) {
        int j;
        inputFile >> j;

        outputFile << intToChar[j];
    }
    inputFile.close();
    outputFile.close();

    return 0;
}