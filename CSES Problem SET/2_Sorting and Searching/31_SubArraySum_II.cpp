#include <bits/stdc++.h>
using namespace std;

#define e long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    e n, x;
    cin >> n >> x;
    vector<e> arr(n);
    for (auto &a : arr) {
        cin >> a;
    }

    map<e, e> prefs;
    e sum = 0, ans = 0;
    prefs[0] = 1;

    for (auto a : arr) {
        sum += a;
        ans += prefs[sum - x];
        prefs[sum]++;
    }

    cout << ans << endl;

    return 0;
}
