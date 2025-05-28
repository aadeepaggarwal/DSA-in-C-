#include <iostream>
using namespace std;
int main() {
     int N;
    int i;
    cout << " enter the value of N:";
    cin >> N;

    for (int i=2; i <= N;i += 1)

    {
        
        int flag = 1;// as of now we will mark the number "i" as prime by flag=0
       // loop to check wheter i is prime or not
        for (int j = 2;j <= i - 1;j += 1)
        {
            if (i % j == 0)// we could have added a condition && flag==1 for better time complexity
            {
                flag = 0;
                break; // if the flag is marked as o then we come out of the loop
            }
            
        }

        if (flag == 1)
        {
            cout << i << " ";
        }
        
    }
    return 0;
}