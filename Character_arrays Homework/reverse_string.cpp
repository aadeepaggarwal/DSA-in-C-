#include <iostream>
#include<cstring>
using namespace std;

void reverse(char *ch){
    int n=strlen(ch);
    for(int i=0;i<n/2;i++){
        swap(ch[i],ch[n-i-1]);// swap 1st and last element each time

    }
    cout<<ch;
}
int main() {
    char a[100];
    cin.getline(a,100);
    reverse(a);
    //cout<<a;
    return 0;
}