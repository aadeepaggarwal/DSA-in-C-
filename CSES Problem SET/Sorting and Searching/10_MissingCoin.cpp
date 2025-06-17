#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long smallest_unreachable = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > smallest_unreachable) break;
        smallest_unreachable += coins[i];
    }

    cout << smallest_unreachable << endl;
    return 0;
}
