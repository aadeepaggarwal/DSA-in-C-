#include <iostream>
using namespace std;
int sumA(int *a,int n){// sabse pehla element hatayenge
    // base case when none element is left
    if( n==0){
        return 0;
    }
    // recursive relation
    return a[0]+ sumA( a+1, n-1);
}
int sumB(int *a,int n){ // last ka ek element hatayenge ab
    // base case when none element is left
    if( n==0){
        return 0;
    }
    // recursive relation
    return  sumB( a, n-1) + a[n-1];
}
int sumC(int *a,int n,int i){ // last ka ek element hatayenge ab
    // base case when none element is left
    if( i==n ){
        return 0;
    }
    // recursive relation
    return  a[i]+ sumC( a, n,i+1);// index same rahega 0 se nahi hoga
}

int main() {
    int n;
    cout<<"enter the size :";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the value of "<< i<<"th index :";
        cin>>a[i];
    }
    
    // int a[]={1,2,3,4,5,6,7};
    // int n= sizeof(a)/sizeof(int);
   cout<< sumA(a,n)<<" is the sum of all the elements of the array."<<'\n';
   cout<< sumB(a,n)<<" is the sum of all the elements of the array."<<"\n";
   cout<< sumC(a,n,0)<<" is the sum of all the elements of the array.";
    return 0;
}