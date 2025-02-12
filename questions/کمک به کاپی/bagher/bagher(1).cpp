#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> output;  
    string line;
    
    for (int i = 0; i < 5; i++) {
        getline(cin, line); 
        
       
        if (line.find("MOLANA") != string::npos || line.find("HAFEZ") != string::npos) {
            output.push_back(i + 1);  
        }
    }

    if (output.size() > 0) {
        for (int num : output) {
            cout << num << " ";  
        }
        cout << endl;
    } else {
        cout << "NOT FOUND!" << endl;  
    }

    return 0;
}

