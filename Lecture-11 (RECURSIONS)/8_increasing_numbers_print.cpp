#include <iostream>
using namespace std;
void print_increasing(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    print_increasing(n - 1);// pehle call hote hote base 0 tak gaya fir print kara 1 se n tak
    cout << n << " ";
}
void decreasing_print(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    decreasing_print(n - 1);// print and call means n print hua neeche gaye so decreasing
}
void increasing(int n, int i)
{
    // base if i==n+1
    if (i == n + 1)
    {
        return;
    }
    cout << i << " ";// iterator wala method 
    increasing(n, i + 1);
}
int main()
{
    int n;
    cout << "enter the number : ";
    cin >> n;

    print_increasing(n);
    cout << '\n';
    decreasing_print(n);
    cout << '\n';
    increasing(n, 1);
    return 0;
}