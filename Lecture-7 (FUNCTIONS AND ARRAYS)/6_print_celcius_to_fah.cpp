#include <iostream>
using namespace std;
void printtable( int initial, int final, int step){
     while (initial <= final)
    {
        cout << "Fahrenhiet value is: " << initial << " "<< "Celcius value is: " << (initial - 32) * (5 / 9.0) << '\n';
// add decimal in formula for decimal output float type
        initial = initial + step;
    }
}
int main() {
    int initial, final, step;
    cout << "enter initial final and step :";
    cin >> initial >> final >> step;
    printtable(initial,final,step);
    return 0;
}