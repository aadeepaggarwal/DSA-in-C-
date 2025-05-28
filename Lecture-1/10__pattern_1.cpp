#include <iostream>
using namespace std;
// 1
// 23
// 456
// 5678
int main()
{

    int N;
    cout << " Enter the number of rows";
    cin >> N;
    int row = 1;
    int j = 1;// j would be the number which we print every time, here it is meant to be initialized outside the loop.

    while (row <= N)
    {
        int k = 1;// for the inner loop where we print the numbers row times, so we set k=1 everytime and iterate till row number.
        while (k <= row)
        {
            cout << j << " ";
            j += 1; // same as j= j+1
            k += 1; // this is the assignment operator
        }
        cout << '\n';

        row += 1;
    }

    return 0;
}
