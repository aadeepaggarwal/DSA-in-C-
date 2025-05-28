#include <iostream>
using namespace std;
void find_a_digit(int *a, int n, int key)
{ // puchh 0th pe hai check karke baki recursion i+1 dekhega
    // or take f(a,n) and call on f(a+1,n-1)
    // base if i=n

    if (n == 0)
    {
        cout << "not found";
        return;
    }

    // recursion

    if (a[n - 1] == key)
    {

        cout << "last index " << n - 1 << "\n ";

        return;
    }
    else
        find_a_digit(a, n - 1, key);
}
int main()
{
    int n, key;
    cout << "enter the size and key : ";
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the element at index " << i << " ";
        cin >> a[i];
    }
    find_a_digit(a, n, key);

    return 0;
}