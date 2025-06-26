#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        // Check if sum is divisible by 3 and each pile is at most double the other
        if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}