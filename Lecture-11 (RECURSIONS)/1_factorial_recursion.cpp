#include <iostream>
using namespace std;
int factorial(int n){
    //base case factorial of 0
    if(n==0){
        return 1;
    }
    //recursive case
    // factorial(n)=n*factorial(n-1)
    int chhota_ans= factorial(n-1);
    int bada_ans= n* chhota_ans;
    return bada_ans;
}
int main() {
    int n;
    cout<<"enter the number for factorial :";
    cin>>n;
    cout<< factorial(n);
    return 0;
}