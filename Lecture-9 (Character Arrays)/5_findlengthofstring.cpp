#include <iostream>
using namespace std;
int length(char *ch){
    int count=0;
    int i=0;
    while(ch[i]!='\0'){
        count++;
        i++;
    }
    return count;
}
int main() {
    char a[100];
    cin.getline(a,100);
    cout<< length(a);
    return 0;
}