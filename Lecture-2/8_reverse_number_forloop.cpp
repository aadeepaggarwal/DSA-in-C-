#include <iostream>
using namespace std;
int main() {
    int N;
    cout<<"Enter the number to be reversed";
    
    int rev=0;
    for ( cin>>N ; N > 0; N=N/10)// we can leave the intialization condition blank like this if already we have the variable above
    {                            // or we can write cin>>N there at intialization place
       rev=(rev*10)+ N%10; 
    }
    cout<< rev;
    return 0;
}