#include <iostream>
// take input of 5 numbers out which only 1 is unique, find that number eg. 1 2 1 2 3 (ans must be 3)
using namespace std;
int main()
{
    int N;
    cout << "Enter the number of inputs";
    cin >> N;
    if (N % 2 == 0)
    {
        cout << "N cannot be even";
    }
    else
    {
        int output = 0; // because 1st time 0 XOR Number is number and later iterator works
        for (int i = 1; i <= N; i++)
        {
            int a;
            cin >> a;
            output = output ^ a; // '^' is the symbol for XOR
        }
        cout << output << " is the unique number";
    }
    return 0;
}
