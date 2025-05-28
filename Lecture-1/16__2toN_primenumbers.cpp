#include <iostream>
using namespace std;
int main()
{
    int N;
    int i = 2;
    cout << " enter the value of N:";
    cin >> N;

    while (i <= N)

    {
        int j = 2;
        int flag = 1;// as of now we will mark the number "i" as prime by flag=0
       // loop to check wheter i is prime or not
        while (j <= i - 1)
        {
            if (i % j == 0)// we could have added a condition && flag==1 for better time complexity
            {
                flag = 0;
                break; // if the flag is marked as o then we come out of the loop
            }
            j += 1;
        }

        if (flag == 1)
        {
            cout << i << " ";
        }
        i += 1;
    }
    return 0;
}