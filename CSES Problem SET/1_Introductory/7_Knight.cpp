#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        long long total = 1LL * i * i * (i * i - 1) / 2;
        long long attack = (i > 2) ? 4LL * (i - 1) * (i - 2) : 0;
        cout << total - attack << endl;
    }
    return 0;
}