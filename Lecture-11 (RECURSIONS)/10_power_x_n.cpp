#include <iostream>
using namespace std;
int power(int x,int n){
    // base case if n==0
    if (n==0)
    {
       return 1; 
    }
    return x*power(x,n-1);
    
}
int main() {
    int n,x;
    cin>>n>>x;
   cout<< power(n,x);
    return 0;
}