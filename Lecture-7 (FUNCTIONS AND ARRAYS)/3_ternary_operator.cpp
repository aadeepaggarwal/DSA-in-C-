#include <iostream>
using namespace std;
// It is basically a short hand notation of if else
int main() {
    int a=10;
    // (condition) ? OnTrue_yeChalega: OnFalse_YeChalega;
    (a%2==0)? cout<<"Even\n": cout<<"Odd\n";

    // we can even assign values using ternary opeartor
    int x=((a>5)? 5000:-5000);
    cout<<x;
    // means agar x 5 se bada hai to +5000 dedo warna -5000
    return 0;
}