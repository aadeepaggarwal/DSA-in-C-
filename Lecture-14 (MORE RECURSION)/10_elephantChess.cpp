#include <iostream>
using namespace std;

int ways(int n, int m){
    // base case
    if (n==0 and m==0) 
    {
        return 1;
    }
    // recursive case
    int sum=0;
    // make 2 for loops of sum behind and above
    for (int k =n-1; k >=0; k--)
    {
       sum+=ways(k,m);// ye loop upar ke sab ka sum dega
    }
    for (int k =m-1; k >=0; k--)
    {
        sum+=ways(n,k);// ye loop peeche ke sab ka sum lelega
    }
    
    
    return sum;
    
}
int main() {
    
    cout<<ways(3,3)<<endl;
    return 0;
}