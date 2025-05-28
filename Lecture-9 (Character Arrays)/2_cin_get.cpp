#include <iostream>
using namespace std;
void inputstring(char *a,int s, char delimiter='\n'/*default argument 
jo sabse pehle rightmost pe aati hai fir aage dalni hai to dal do*/){

    int i=0;
    char ch;
    ch=cin.get();
    while(ch!=delimiter and i<s-1/*means input till delimiter or if size khatam*/){
        a[i++]=ch;
        ch=cin.get();
    }
    a[i]='\0';
}
int main() {
    // normal array char type ka space aane tak lelega array ka
    char a[100];
    cin>>a;
    cout<<a;// couts all till first space or enter or tab

    // i want input till '\n' aaye.(enter dabane tak hence)
    // means whitespaces pe ignore nahi hoga input

    char b[88];// we can take custom size bhi cin>>n; b[n] leke
    inputstring(b,88); // can use inbuilt feature cin.getline(character array,size,delimiter)
    cout<<b;
    return 0;
}