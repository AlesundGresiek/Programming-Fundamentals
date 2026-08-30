#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

int main() {
    cout << isLeapYear(2024);
    return 0;
}
