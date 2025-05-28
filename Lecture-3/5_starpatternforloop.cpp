#include <iostream>
using namespace std;
// *
// **
// ***
int main() {
    int row, star;
    int n;
    cin>>n;
    for (row = 1; row <= n; row++)
    {
        for (star = 1; star <= row ; star++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}