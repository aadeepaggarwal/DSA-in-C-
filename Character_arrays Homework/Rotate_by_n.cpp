#include <iostream>
#include<cstring>
using namespace std;
void rotate(char *ch,int n){
    int len=strlen(ch);
    for (int j = 1; j <= n; j++)
    {
        char temp=ch[len-1];
        for (int i = len-1; i >0 ; i--)
        {
            ch[i]=ch[i-1];
        }
        ch[0]=temp;
        
        
    }
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