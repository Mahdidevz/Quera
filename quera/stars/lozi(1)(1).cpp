#include <iostream>
using namespace std;

void printStarDiamond(int n) {
    for (int i = 1; i <= n; i++) {
      if(i % 2 != 0) {
        for (int j = 1; j <= ( n - i)/2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (i); j++) {
            cout << "*";
        }
        for (int j = 1; j <= (n - i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= (i); j++) {
            cout << "*";
        }
        cout << endl;
      }
    }

    for (int i = n - 1; i >= 1; i--) {
      if(i % 2 != 0) {
        for (int j = 1; j <= (n - i)/2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= (i); j++) {
            cout << "*";
        }
        for (int j = 1; j <= (n - i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= (i); j++) {
            cout << "*";
        }
        cout << endl;
      }

    }
}

int main() {
    int n;
    cin >> n;
    if (n >= 1 && n <= 19) {
        printStarDiamond(n);
    } 
    return 0;
}