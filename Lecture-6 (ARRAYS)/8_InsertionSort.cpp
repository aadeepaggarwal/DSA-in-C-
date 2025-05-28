#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "enter the size of array :";
    cin >> N;
    int A[N];
    // take input of array
    for (int i = 0; i < N; i++)
    {
        cout << " enter the array index position for index- " << i << " ";
        cin >> A[i];
    }

    // code of insertion sort
    // assume initialy the 1st element to be sorted

    for (int i = 1; i < N; i++)
    {
        int k = A[i];
        int j ;
        for (j = i - 1; A[j]>k &&j >= 0; j--) // very important: condition of this is to see if k is smaller then only be in the loop 
        {// in c++ && means same as and we can use and direct and we can use 'or' as well
            // if I apply if else then else pe add a break if K is no more greater than A[j]
            {
                A[j + 1] = A[j];
            }
        }
        A[j + 1] = k;
    }

    // for (int i = 1; i < N; i++)
    // {
    //     int k = A[i];
    //     int j = i - 1;

    //     while (j >= 0 && A[j] > k) // keep shiftinf in sorted array till the k is smaller than last element of sorted part
    //     {
    //         A[j + 1] = A[j];
    //         j--;
    //     }

    //     A[j + 1] = k;
    // }

    // print final sorted array
    cout << " Sorted array by insertion sort is: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}