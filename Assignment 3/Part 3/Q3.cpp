#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;//0
        b = a % b;//0
        a = temp;//6
    }
    return a;
}

int main() {
    cout << findGCD(48, 18);
    return 0;
}
