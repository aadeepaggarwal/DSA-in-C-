#include <iostream>
using namespace std;
int main() {
// 1st way
    char ch='A';
    while(ch<='Z'){// ASCII of Z is 90
        cout<< ch<<"\n";
        ch++;
    }

// 2nd way

    int i=0;
    while (i<=25)
    {   
        char ch= 'A'+i;
        cout<< ch<<'\n';
        i++;
    }
    
    return 0;
}
