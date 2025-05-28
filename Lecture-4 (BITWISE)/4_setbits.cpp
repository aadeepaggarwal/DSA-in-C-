#include <iostream>
using namespace std;
// find the set bits of a number in its binary form. Set bits means number of 1's in a number's binary representaion
int main() {
    int N;
    cout<<"Enter the number";
    cin>>N;
    int ans=0;// to count the total set bits
    while(N)// means till N is not equal to 0
    {
        if(N&1==1){
            ans++;
        }
        N=N>>1;
    }
    cout<<"Set Bits are: "<< ans;
    return 0;
}