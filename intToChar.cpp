#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    string f;
    string o;
    cout << "enter file to translate" << endl;
    cin >> f;
    cout << "enter file to output to" << endl;
    cin >> o;

    ifstream inputFile;
    ofstream outputFile(o);

    inputFile.open(f);

    // initializing int, char map for decoding
    map<int, char> intToChar;

    intToChar['2'] = 'a';
    
    for (int i = 2; i != 28; ++i) {
        char a = 'a';
        intToChar[i] = a;
        ++a;
    }

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