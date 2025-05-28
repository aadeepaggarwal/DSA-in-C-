#include <iostream>
#include<cstring>
using namespace std;
void rotate(char *ch,int n){
    int len=strlen(ch);
    int i=len-1;
    while (i>=0)
    {
        ch[len-1+n]=ch[i--];
    }
    i=0;
    while(i<n){
        ch[i]=ch[len+i];
        i++;
    }
    ch[len+1]='\0';
    
    cout<<ch;
    
}
int main() {
    int n;
    cout<<"enter the reverse number : ";
    cin>>n;
    cin.ignore();// because n and string input wala lafda
    char a[100];
    cin.getline(a,100);
    rotate(a,n);
    return 0;
}