#include <iostream>
using namespace std;
int main() {
    cout << "ASCII Values of Uppercase Alphabets:" << endl;
    for(char c = 'A'; c <= 'Z'; c++) {
        int av = static_cast<int>(c);
        cout << c << " : " << av << endl;
    }
    cout << endl;
    cout << "ASCII Values of Lowercase Alphabets:" << endl << endl;
    for (char c = 'a'; c <= 'z'; c++) {
        int asciiValue = (int)c; 
        cout << c << " : " << asciiValue << endl;
    }
    cout << endl;
}

