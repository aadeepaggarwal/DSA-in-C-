#include <iostream>
using namespace std;
int main() {
    long long n;
    cin>>n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout<<1<<" ";
    return 0;
}