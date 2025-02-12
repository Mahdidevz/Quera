#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    int temp;
    cin>> n;
    temp = n;
    int sum = 0;
    while (n > 0)
    {
        sum = (sum*10)+(n%10);
        n/=10;
    }
    if (temp == sum)
    {
        cout << "YES";
    }
    else 
        cout << "NO";
    
    
    
}