#include <iostream>
#include<stack>/*stl se stack us ekarle ab to*/
using namespace std;

bool isBalanced(char *a){
    stack <char> s;
    for (int i = 0; a[i]!='\0'; i++)
    {
        char ch=a[i];
        switch (ch)
        {
        case '(':
        case '{':   
        case '[':  
            s.push(ch);  
            break;
        case ')':
            if (s.empty() || s.top()!='(')
            {
               return false;
            }
            else s.pop();
            break;
            
        case '}':
            if (s.empty() || s.top()!='{')// yaha dekho har bar ki kya stack khali to nahi agar closing bracket aya, aur agar khali nahi hai to kya uska band karne wala hai ya nahi agar han to pop kardo uska sathi aur aage badho
            {
               return false;
            }
            else s.pop();
            break;
        case ']':
            if (s.empty() || s.top()!='[')
            {
               return false;
            }
            else s.pop();
            break;
        default:
            break;
        }
    }
    // yaha ab agar empty nahi hai stack to false and agar empty hai matlab balanced tha
    return s.empty();
}
int main() {
    char a[]="{a + [b+(c+d)] + (e + f)}";
    if (isBalanced(a))
    {
        cout<<" Balanced \n";
    }
    else cout<<" Not Balanced \n";
    
    return 0;
}