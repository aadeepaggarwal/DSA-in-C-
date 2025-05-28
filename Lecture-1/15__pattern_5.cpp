#include <iostream>
using namespace std;
// * * * * *
// * *   * *
// *       *

int main()
{
    int N;
    cout << "Enter the number of rows: ";
    cin >> N;
// First we will print all the stars of the first row 
    int i = 1;
    while (i <= (2 * N - 1))
    {
        cout << "* ";
        i += 1;
    }
    cout << '\n';

    int row = 1;
    while (row < N)
    {
        // 1. in every subsequent row we now print the N-row stars 1st then 2*row-1 spaces and again N-row stars.
        int j = 1;
        while (j <= (N - row))
        {
            cout << "* ";
            j++;
        }

        // 2.
        int k = 1;
        while (k <= ((2 * row) - 1))
        {
            cout << "  ";
            k += 1;
        }

        // 3.
        j = 1;
        while (j <= (N - row))
        {
            cout << "* ";
            j++;
        }

        cout << '\n';
        row += 1;
    }

    return 0;
}
