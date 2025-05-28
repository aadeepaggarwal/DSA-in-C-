#include <iostream>
using namespace std;
int main()
{

    int N;
    int i = 2;
    cout << " enter the value of N:";
    cin >> N;

    while (i <= N / 2)
    {
        if (N % i == 0) // if N gets divided by any one number as well then it won't be prime
        {
            cout << " Not prime";
            return 0;
        }
        i += 1;
    }
    cout << "Prime"; // if the loop does not end inside then we come out means it is prime

    return 0;
}