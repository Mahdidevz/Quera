#include <iostream>

using namespace std;

string checkWeight(int height, int weight) {
  if (height < 150) {
    if (weight < 40) {
      return "laghar";
    } else if (weight > 40 && weight < 50) {
      return "normal";
    } else {
      return "chagh";
    }
  } else if (height > 150 && height < 180) {  
    if (weight < 50) {
      return "laghar";
    } else if (weight > 50 && weight < 80) {
      return "normal";
    } else {
      return "chagh";
    }
  } else if (height > 180) {
    if (weight < 80) {
      return "laghar";
    } else if (weight > 80 && weight < 90) {
      return "normal";
    } else {
      return "chagh";
    }
  } else {
    return"";
  }
}

int main() {
  int height, weight;


  cin >> height;

  cin >> weight;

  cout << checkWeight(height, weight) << endl;

  return 0;
} 