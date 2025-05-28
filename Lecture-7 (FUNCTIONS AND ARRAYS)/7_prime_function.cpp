#include <iostream>
using namespace std;

bool Check_prime(int a){
    int i=2;
    for ( ;i < a/2; i++)
    {
       if (a%i==0)
       {
        return 0;// agar divide hua to false
       }
       
    }
    return 1; // divide hua hi nahi to true
    
}
int main() {
    int N;
    cout << "enter the number to be checked :";
    cin >> N;

    cout << Check_prime(N)<<'\n';
    if (Check_prime(N) == 1)
    {
        cout << "Prime\n";
    }
    else
    {
        cout << "Not Prime \n";
    }

    return 0;
}