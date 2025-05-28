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
void Print_Primes(int a){

    for (int i = 2; i <= a; i++)
    {
        if (Check_prime(i)==1)// use function mein function like this
        {
            cout<<i<<" ";
        }
        
    }
    
}
int main() {
    int N;
    cout<<"enter the value of N :";
    cin>>N;
    Print_Primes(N);
    return 0;
}