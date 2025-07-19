#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    vector<long long> arr(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pref[b] - pref[a - 1] << endl;
    }
    return 0;
}