#include <iostream>
using namespace std;
int multiply(int a,int b){
    // base case
    if(b==0) return 0 ;
    // recurrence relation 
    return a+ multiply(a,b-1);
}
int main() {
    int a,b;
    cout<<"enter a and b  : ";
    cin>>a>>b;
    cout<< multiply(a,b);
    return 0;
}