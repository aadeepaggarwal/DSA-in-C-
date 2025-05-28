#include <iostream>
using namespace std;

// *
// * *
// * * *
// * * * *

int main() {
    int N;
    cout<<"Enter the number of rows: ";
    cin>> N;

    int row=1;

    while(row<=N){
        int k=1;
        while(k<=row){
            cout<<'*'<<" ";
            k+=1;
        }
        cout<<'\n';
        row+=1;

    }


    return 0;
}

