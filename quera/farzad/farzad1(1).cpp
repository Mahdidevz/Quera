#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> movie_names;
    
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, name);
        movie_names.push_back(name);
    }

    for (const string& name : movie_names) {
        string res = "";
        stringstream ss(name);
        string word;
        vector<string> ocd_list;
        
        while (ss >> word) {
            word[0] = toupper(word[0]);
            for (size_t i = 1; i < word.length(); i++) {
                word[i] = tolower(word[i]);
            }
            ocd_list.push_back(word);
        }
        
        for (size_t i = 0; i < ocd_list.size(); i++) {
            res += ocd_list[i];
            if (i < ocd_list.size() - 1) {
                res += " ";
            }
        }
        
        cout << res << endl;
    }

    return 0;
}
