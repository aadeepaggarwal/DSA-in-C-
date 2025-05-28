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

    // main code for selection sort

    for (int i = 0; i < N; i++)
    {
        int smallest = i; // store the index not it's value right now
        // assumed that till now the smallest value is on the ith index only
        for (int j = i; j < N; j++)
        {
            if (A[smallest] > A[j])
            {
                smallest = j;
            }
        }
        // swap with that smallest element
        // int temp = A[i];
        // A[i] = A[smallest];
        // A[smallest] = temp;
        // Or use inbuilt function swap
        // swap(element1, element2)--->
        swap(A[i], A[smallest]);
        
    }

    // print final sorted array
    cout << " Sorted array is: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}