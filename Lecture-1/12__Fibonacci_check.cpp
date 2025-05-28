#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 1;
    int c = a + b;
    int N;
    cout << " enter the number to be checked";
    cin >> N;
    while (c <= N)
    {
        if (c < N)
        {
            a = b;
            b = c;
            c = a + b;
        }
        else
        {
            cout << " Yes the number is fibonacci";
            return 0;
        }
    }
    cout << "Not in series";
    return 0;
}
