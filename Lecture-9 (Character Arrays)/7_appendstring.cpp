#include <iostream>
#include<cstring>
using namespace std;
// TAKE 2 STRINGS A AND B, A WITH LARGER SIZE AND APPEND B IN A
void append(char *str1,char*str2){
    int m=strlen(str1), n=strlen(str2);

    int i=m,j=0;// we took 1st string assume karke ki size bada hai and i shuru kar 1st string ke end se and str2 copy karte rahe 
    while(j<=n){// j at str2 ke start pe i at str1 ke current end pe
        str1[i++]=str2[j++];
    }
    
}
int main() {
    char a[100]="Hey";
    char b[100]="There";
    append(a,b);
    cout<<a;

    // can use default function strcat(a,b) too instead of this whole thing
    return 0;
}