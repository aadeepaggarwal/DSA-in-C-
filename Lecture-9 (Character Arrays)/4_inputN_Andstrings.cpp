#include <iostream>
using namespace std;
void takeNandString(){
    char a[100];
    int n;
    cin>>n;
    cin.ignore(); // cin.get bhi likh sakte hi khali

    for(int i=0;i<n;i++){
        cin.getline(a,100);
        cout<<"string was  : "<<a;
    }
}
int main() {
    // ek number ka input lena  hai aur string ka bhi with size of that number 
    takeNandString();
    return 0;
}