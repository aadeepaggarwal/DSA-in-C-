#include <iostream>
using namespace std;
// ABCDEFFEDCBA
// ABCDEEDCBA
// ABCDDCBA
// ABCCBA
// ABBA
// AA
int main()
{
    int N;
    cin >> N;
    int ch;
    for (int row = 1; row <= N; row++)
    {   // or introduce char='A' here and loop for i = 1 to N-row+1 and meanwhile add ch++ condition after printing each time
        for (ch = 1; ch <= N - row + 1; ch++)
        {
            cout << char(ch + 64)<<" ";
        }
        ch--;// in other case also do same ch-- after coming out of the loop
        for (; ch > 0; ch--)
        {
            cout << char(ch + 64)<<" ";// add ch-- here if cout<<ch is done in 2nd oprion code
        }
        cout << endl;
    }
    return 0;
}