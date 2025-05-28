#include <iostream>
using namespace std;
int main() {
    char ch;
    cin>> ch;
    if(ch>=65 && ch<=90){
        cout<<"This is UPPERCASE";
    }
    else if(ch>=65 && ch<=90){
        cout<<"LOWERCASE";
    }
    else
    cout<<"INVALID";
    return 0;
}
