#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> arr(10);
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> result;

    for (int i = 0; i < 10; ) {
        int count = 1;
        while (i + count < 10 && arr[i + count] == arr[i]) {
            count++;
        }

        int toAdd = min(count, k);
        if (count >= k) {
            toAdd = k - 1;
        }

        for (int j = 0; j < toAdd; j++) {
            result.push_back(arr[i]);
        }

        i += count;
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
