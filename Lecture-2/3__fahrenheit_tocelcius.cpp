#include <iostream>
using namespace std;
int main()
{
    int initial, final, step;
    cout << "enter initial final and step";
    cin >> initial >> final >> step;

    while (initial <= final)
    {
        cout << "Fahrenhiet value is: " << initial << " "<< "Celcius value is: " << (initial - 32) * (5 / 9.0) << '\n';
// add decimal in formula for decimal output float type
        initial = initial + step;
    }
    return 0;
}
