#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    
    string s = "";
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;  
        s += row;  
    }
    
    int count = 0;
    for (char c : s) {
        if (c == '*') {
            count++;  
        }
    }
    
    cout << count << endl;

    return 0;
}

