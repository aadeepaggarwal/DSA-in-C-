#include <iostream>
using namespace std;
int length(char *ch)
{
    int count = 0;
    int i = 0;
    while (ch[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
bool checkPal(char *ch)
{
    int n = length(ch);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else if (ch[i] != ch[j])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    // int n;
    // cin>>n;
    // cin.get();// to ignore one character after n in input ye abhi nahi kar sakte ye galat hai
    char a[100];
    cin.getline(a, 100);
    cout << checkPal(a);
    return 0;
}