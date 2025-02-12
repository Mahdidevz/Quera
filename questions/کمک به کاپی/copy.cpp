#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n >> s;  // Read input for n and s
    
    for (int i = 0; i < n; i++) {
        cout << "copy of ";  // Print "copy of" n times
    }
    
    cout << s << endl;  // Print the string s after the loop

    return 0;
}
