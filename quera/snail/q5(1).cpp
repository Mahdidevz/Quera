#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int counter = 1; 
    int current_pos[2] = {0, 0};

    if (n == 1) {
        cout << "0 0" << endl;
    } else {
        while (counter < n) {
            if (current_pos[0] > 0 && current_pos[1] < 0) {

                current_pos[1] = -current_pos[1] + 1;
            } else if (current_pos[0] > 0 && current_pos[1] > 0) {

                current_pos[0] = -current_pos[0];
            } else if (current_pos[0] < 0 && current_pos[1] > 0) {

                current_pos[1] = -current_pos[1];
            } else if (current_pos[0] < 0 && current_pos[1] < 0) {

                current_pos[0] = -current_pos[0] + 1;
            } else if (current_pos[0] == 0 && current_pos[1] == 0) {

                current_pos[0] = 1;
                current_pos[1] = 0;
            } else if (current_pos[0] == 1 && current_pos[1] == 0) {

                current_pos[0] = 1;
                current_pos[1] = 1;
            }

            counter++;
        }
        cout << current_pos[0] << " " << current_pos[1] << endl;
    }

    return 0;
}
