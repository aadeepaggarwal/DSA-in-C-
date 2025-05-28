#include <iostream>
using namespace std;
int main() {

    // making an array
    int A[5];// here N=5
    //taking input manually 
    // A[0]=1;
    // A[1]=2;
    // A[2]=3;
    // A[3]=4;
    // A[4]=5;

    // taking input
    for (int i = 0; i < 5; i++)
    {
        A[i]=i+1;
    }
    // taking output
    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<' ';
    }
    
    cout<<endl;
    return 0;
}