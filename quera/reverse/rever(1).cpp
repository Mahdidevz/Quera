#include <iostream>
#include <string>
using namespace std;

unsigned long long reverseNumber(unsigned long long num) {
    unsigned long long reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

int main() {
    unsigned long long totalSum = 0;
    while (true) {
        long long input;
        cin >> input;
        if (input == -1) break;
        unsigned long long reversed = reverseNumber(input);
        totalSum += 2 * reversed;
    }
    cout << totalSum << endl;
    return 0;
}
