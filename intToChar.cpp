#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string f;
    string o;
    cout << "enter file to translate" << endl;
    cin >> f;
    cout << "enter file to output to" << endl;
    cin >> o;

    ifstream inputFile(f);
    ofstream outputFile(o);
    
    // take in int and return a file of strings
    while(!inputFile.eof()) {
        int i;
        inputFile >> i;

    }
}