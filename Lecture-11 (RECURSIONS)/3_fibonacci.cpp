#include <iostream>
using namespace std;
int fib(int n){
    // base case
    if(n==1) return 1;
    else if(n==0) return 0;

    // reccurence realtion
    //fib(n)=fib(n-1)+ fib(n-2)
    int chhota1=fib(n-1);
    int chhota2= fib(n-2);
    int bada_ans=chhota1+chhota2;
    return bada_ans;// or return fib(n-1)+fib(n-2)
}
int main() {
     int n;
    cout<<"enter the position for fibonacci:";
    cin>>n;
    cout<< fib(n);
    return 0;
}