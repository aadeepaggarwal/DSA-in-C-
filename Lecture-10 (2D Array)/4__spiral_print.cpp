#include <iostream>
using namespace std;

void spiralprint(int a[][4], int rows, int cols)
{
    int sr = 0, er = rows - 1, sc = 0, ec = cols - 1;
    while (sr <= er and sc <= ec)
    {
        // 1. sr from sc to ec

        for (int i = sc; i <= ec; i++)
        {
            cout << a[sr][i] << " ";
        }
        sr++;

        // 2. ec from sr to er
        for (int i = sr; i <= er; i++)
        {
            cout << a[i][ec] << " ";
        }
        ec--;
        // 3. er from ec to sc
        for (int i = ec; i >= sc; i--)
        {
            cout << a[er][i] << " ";
        }
        er--;

        // 4. sc from er to sr
        for (int i = er; i >= sr; i--)
        {
            cout << a[i][sc] << " ";
        }
        sc++;
    }
}
int main()
{

    int a[][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 10},
        {11, 12, 13, 14}};
    spiralprint(a, 4, 4);

    return 0;
}