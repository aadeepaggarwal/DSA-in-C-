#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    // Initial count of rounds
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) rounds++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int va = arr[a], vb = arr[b];
        set<pair<int, int>> affected;

        for (int d = -1; d <= 1; d++) {
            if (1 <= va + d && va + d < n)
                affected.insert({va + d, va + d + 1});
            if (1 <= vb + d && vb + d < n)
                affected.insert({vb + d, vb + d + 1});
        }

        // Remove effect before swap
        for (auto [x, y] : affected) {
            if (pos[x] > pos[y]) rounds--;
        }

        // Perform the swap
        swap(arr[a], arr[b]);
        swap(pos[va], pos[vb]);

        // Add effect after swap
        for (auto [x, y] : affected) {
            if (pos[x] > pos[y]) rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}
