#include <iostream>

/*
    1
  1 2 3
1 2 3 4 5

*/
using namespace std;
int main()
{

    int N;
    cout << " enter the rows:";
    cin >> N;
    int row = 0;

    while (row < N)
    {
        {
            int i = 1;
            while (i < (N - row))
            {
                cout << "  ";
                i += 1;
            }
        }
        {
            int j = 1;
            while (j <= ((2 * row) + 1))
            {
                cout << j << " ";
                j += 1;
            }

            cout << '\n';
            row += 1;
        }
    }

    return 0;
}