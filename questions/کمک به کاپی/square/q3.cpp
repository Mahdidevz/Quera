#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n-1 || j ==0)
            {
                cout << '*';
                continue;
            }
            else if (i == n-1 || i ==0)
            {
                cout << '*';
                continue;
            }
            else {
                cout << ' ';
            }
            
        }
        cout <<'\n';
        
    }
    
}