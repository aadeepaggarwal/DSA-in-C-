#include <iostream>
using namespace std;
int main() {
    int A[10]={1,2,3,4,5};

    for (int i = 0; i < 10; i++)
    {
        cout<<A[i]<<" ";// after 1st 5 next 5 output will be 0 and not garbage because we have intialized the array 
    }
    
    return 0;
}