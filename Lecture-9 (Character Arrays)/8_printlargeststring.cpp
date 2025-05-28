#include <iostream>
#include <cstring>
using namespace std;
void inputstring(char *a, char delimiter='\n'/*default argument jo sabse pehle rightmost pe aati 
                                               hai fir aage dalni hai to dal do*/){

    int i=0;
    char ch;
    ch=cin.get();
    while(ch!=delimiter ){
        a[i++]=ch;
        ch=cin.get();
    }
    a[i]='\0';
}
int main() {

    int n;
    int max=0;
    cin>>n;
    cin.ignore();
    char ch[10000];
    char largest[max];
    for (int i = 0; i <n; i++){
        inputstring(ch);// or cin.geline(ch,10000)
        int n=strlen(ch);
        if(n>max){
        max=n;
        strcpy(largest,ch);
        }
    }
    cout<<largest;
        
    return 0;
}