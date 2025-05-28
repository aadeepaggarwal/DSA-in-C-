#include <iostream>
using namespace std;
/*
two arrays are given of size 1st one of M+N.
 only M elements are there in 1st array an only N elements are there in 2nd array
 hence merge two arrays in 1st array that too sorted form
 */

void print_array(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
}

void input(int N, int a[])
{
    cout<< "give input for the array \n";
    for (int i = 0; i < N; i++)
    {
        cout << "enter the value of " << i << "th index : ";
        cin >> a[i];
    }
}

void mergesortedarray(int a[], int m, int b[], int n)
{

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 and j >= 0)
    {
        if (b[j]>a[i])
        {
            a[k--]=b[j--];
        }
        else
            a[k--]=a[i--];
        
    }

    // note that if b ke elements bache hai to tab to ham a mein dalenge magar agar a mein hi hai to nahi dalenge kyonki already sorted
    while(j>=0){
        a[k--]=b[j--];
    }

    cout<<"merged array is : ";
    print_array(a,m+n);
}
int main()
{
    int m, n; // use m=2 n=3
    cout <<" enter the value of m and n : ";
    cin >> m>> n;
    int A[m + n], B[n];

    // take input of arrays
     input(m , A);
     input(n, B);
    

    mergesortedarray(A,m,B,n);



    return 0;
}