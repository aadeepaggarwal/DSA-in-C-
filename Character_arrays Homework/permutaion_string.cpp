#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool check_permute(char *a,char *b,int hash[26]){

    int n=strlen(a);
    int m=strlen(b);
    if(n==m){
        int i=0;
        while(i<n){// or while a[i]!='\0'(NULL) or simply while(a[i])
           if(a[i]>'a' and a[i]<'z') { hash[a[i]-97]++;}//instead of 97 seedha a likhde
           else {hash[a[i]-65]++;}// instead of 65 seedha A likhde
            i++;
        }
        int j=0;
        while(j<m){
           if(b[j]>'a' and b[j]<'z') { hash[b[j]-97]--;}
           else {hash[b[j]-65]--;}
            j++;
        }
        j--;
        while(j>=0)
        {if (hash[j]==0){
            j--;

            }
        else return 0;
        }
        return 1;
    }
    else return 0;

}

int main() {
    int hash[26]={0};
    cout<<"enter string 1: ";
    char a[100];
    cin.getline(a,100);

    cout<<"enter string 2: ";
    char b[100];
    cin.getline(b,100);

   cout<< check_permute(a,b,hash);
    return 0;
}