#include <iostream>
#include <climits>
// -2^31= INT_MIN and INT_MAX= 2^31-1 use this library to use these values
using namespace std;
int main()
{

    int N;
    cout << "Enter the value of N:";
    cin >> N;
    int MX = INT_MIN;
    
    int i = 1;
    while (i <= N)
    {
        int a;// we read a number a every time inside the loop and get its input.
        cout << "enter the number:";
        cin >> a;

        if (a > MX)
        {
            MX = a;
        }
        i += 1;
    }
    cout << " Maximum value is:" << MX;

    return 0;
}
