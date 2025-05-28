#include <iostream>
using namespace std;

// make phoney keypad universally
char keys[][5/*5 because max coulmns 5 hain*/]={
    "","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"
};

void phoneKey(char* ip, int i, char* op, int j){
    // base case
    if (ip[i]=='\0')
    {
        op[j]='\0';
        cout<<op<<endl;
        return;
    }
    
    // recursive case
    int digit =ip[i]-'0';// yaha se input wale character ko integer mein badalenge
    for (int k = 0; keys[digit][k]!='\0'; k++)// digit ko ham recursion se update karenge aur 
    {
        char ch =keys[digit][k];
        op[j]=ch;
        phoneKey(ip,i+1,op,j+1);
    }
    
}
int main() {
    char ip[100];
    cin.getline(ip,100);
    char op[100];

    phoneKey(ip,0,op,0);
    return 0;
}