#include <iostream>
using namespace std;
int main() {
    int i=1;
    int N;
    cout<<"enter the vlaue of N:";
    cin>> N;
    while(i<=N){
        cout<<i<<" ";
        i++;
        if(i==3){
            break; // at 3 it will end and come out of the loop hence it'll only print 1 and 2 and not go till N.
        }
    }

    return 0;
}
