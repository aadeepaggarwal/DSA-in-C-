#include <iostream>
#include <cstring>
using namespace std;
int convert(char *a,int n){
    // base case
    if (n==0)
    {
        return 0;
    }
    
    // recursion
    int last_digit= a[n-1]-'0';
   int value= convert(a,n-1);
    return value*10 +last_digit;
}
int main() {
    char a[]="1234";
    int n= strlen(a);// or sizeof(a)/sizeof(char)
    cout<<convert(a,n)<<'\n';
    cout<<convert(a,n)+10<<'\n';
    cout<<convert(a,n)+15<<'\n';
    return 0;
}
