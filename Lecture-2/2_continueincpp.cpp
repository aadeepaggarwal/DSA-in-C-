#include <iostream>
using namespace std;
int main() {
 int i=1;
    int N;
    cout<<"enter the vlaue of N:";
    cin>> N;
    while(i<=N){
        
        
        if(i==3){
            i++;
            continue; // at 3 it will skip and print all other numbers after 4 till N.
        }
        cout<<i<<" ";// add this print command here because if taken above then it will not take the continue properly
        i++;// add main updation condition after continue and add one in if loop as well
    }



    return 0;
}
