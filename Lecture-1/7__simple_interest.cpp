#include <iostream>
using namespace std;
int main()
{

    float P, R, T; // don't take int because int upon int renders an integer even if out bucket is of float type
    float Simple_interest;
    // take input of P R T
    cout << " Enter the value of P R and T:";
    cin >> P >> R >> T;
    Simple_interest = (P * R * T) / 100; // cam even make numerator or denominator float here by using 100.0 or multiplying 1.0
    cout << " The simple interest is:" << Simple_interest;
    return 0;
}