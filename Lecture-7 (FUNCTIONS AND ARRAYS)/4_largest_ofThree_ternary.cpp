#include <iostream>
using namespace std;
// using ternary operator print the largest number out of the 3

int main()
{
    int a = 10, b = 12, c = 5;
    // we can use ternary operator inside ternary
    (a > b and a > c) ? cout << a : ((b > c && b > a) ? cout << b : cout << c);

    // or sir ka code
    // (a>=b)?
    //     (a>=c)? cout<<a:((b>=a)?
    //                         (b>=c)? cout<<b: cout<<c);
    return 0;
}
