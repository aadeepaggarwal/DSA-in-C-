#include <iostream>
using namespace std;
// printing the reverse of an array
// just run a reverse loop
int main() {
    int a[5]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int);

    for (int i = n-1; i >=0; i--)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}