#include <iostream>
#include <string>
using namespace std;

int main() {
    string rejim;
    cin >> rejim;

    int red = 0, yellow = 0, green = 0;
    
    for (char c : rejim) {
        if (c == 'R') red++;
        else if (c == 'Y') yellow++;
        else if (c == 'G') green++;
    }

    if (red >= 3) {
        cout << "nakhor lite" << endl;
    } else if (red >= 2 && yellow >= 2) {
        cout << "nakhor lite" << endl;
    } else if (green == 0) {
        cout << "nakhor lite" << endl;
    } else {
        cout << "rahat baash" << endl;
    }

    return 0;
}
