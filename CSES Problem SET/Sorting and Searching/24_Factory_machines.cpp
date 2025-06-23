#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canProduce(int time, const vector<int>& machines, int t) {
    long long total = 0;
    for (auto k : machines) {
        total += time / k;
        if (total >= t) return true;  // Early stop
    }
    return false;
}

int32_t main() {
    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    int left = 1, right = 1e18; // upper bound: max time possible
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canProduce(mid, machines, t)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
