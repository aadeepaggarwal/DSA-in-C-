#include <iostream>
using namespace std;
//count the number of characters till we enter a dollar
int main() {
    char ch;
    ch=cin.get();
    int digits =0;
    int whitespaces =0;
    int alphabets =0;
    int others =0;
    while(ch!='$'){
        if(ch>=48&&ch<=57){// can even do ch>='0'&& ch<='9'
            digits++;
        }
        else if ((ch>=65&&ch<=90)||(ch>=97&&ch<=122)){// can do >=a <=z and so on as well ascii ke bina!!
            alphabets++;
        }
        else if (ch=='\t' || ch=='\n' || ch==' '){
            whitespaces++;
        }
        else{
            others++;
        }
        ch= cin.get();
    }
    cout<<"Digits are :"<<digits<<'\n'<<"Alphabets are :"<<alphabets<<'\n'<<"Spaces are :"<<whitespaces<<'\n'<<"Others are :"<<others<<'\n';
    return 0;
}