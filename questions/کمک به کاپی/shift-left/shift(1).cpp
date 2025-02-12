#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr(10);
    int n;
    

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }


    cin >> n;


    n = n % 10;  
    for (int i = 0; i < n; i++) {
        int temp = arr[0]; 
        for (int j = 0; j < 9; j++) {
            arr[j] = arr[j + 1];  
        }
        arr[9] = temp;  
    }


    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
