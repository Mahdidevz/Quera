#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 , str2;
    char op;
    
    cin >> str1;  
    cin >> op;  
    cin >> str2; 
    
    string result;
    

   
    if (op == '+') {
      if (str1.size() == str2.size()) {
        result = "2" + str1.substr(1);
      } else {
        int diff = abs(int(str1.size()) - int(str2.size()));
        

        if (str1.size() > str2.size()) {

            str1 = str1.substr(0 , diff);

            str1 += str2;
            result = str1;
        } else {

            str2 = str2.substr(0 , diff);

            str2 += str1;
            result = str2;
        }
      }
    } else if (op == '*') {
        result = str1 + str2.substr(1);  
    }
    

    cout << result << endl;
    
    return 0;
}