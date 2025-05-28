#include <iostream>
using namespace std;
int main() {

    char ch;
    cin>>ch;
    while(ch!='$'){
        cout<<ch<<'\n';
        cin>>ch;
    }
    return 0;
}