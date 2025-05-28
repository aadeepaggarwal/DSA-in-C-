#include <iostream>
using namespace std;
int main() {
    int l;
    int r;
    cout<<"Enter the value of l and r from 0th bit: ";
    cin>>l>>r;
    cout<<'\n';
    // r se peeche saare 1
    int Lower_bits=((1<<r)-1);
    // l se aage wale sare 1
    int Upper_bits= (~0<<l+1);// we tool l+1 because lth position means 0 ke baad l so total number of shifts required here are l+!
    // output mask type 1
    int mask= (Lower_bits | Upper_bits);
    // now use the function to print 32 bits done before
    // copy it as it is 

    for (int i = 31; i >= 0; i--)
    {
        if ((mask & (1<<i)) == 0)
        {
            cout << "0 ";
        }
        else
        {
            cout << "1 ";
        }
        
    }
    return 0;
}