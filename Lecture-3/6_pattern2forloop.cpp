#include <iostream>
using namespace std;
// 1
// 01
// 101
// 0101
int main()
{
    int N;
    cin >> N;
    for (int row = 1; row <= N; row++)
    {
        int x;
        if (row % 2 == 0)
        {
            x = 0;
        }
        else
        {
            x = 1;
        }

        for (int i = 1; i <= row; i++)
        {
            cout << x << ' ';
            x = 1 - x;
        }
        cout << '\n';
    }

    return 0;
}
