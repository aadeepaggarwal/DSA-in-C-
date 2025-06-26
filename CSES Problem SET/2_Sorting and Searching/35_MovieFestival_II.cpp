#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> arr(n);
    for (auto &a : arr) {
        cin >> a[0] >> a[1]; // Read start and end time
    }

    // Sort by end time
    sort(arr.begin(), arr.end(), [](array<int, 2> &a, array<int, 2> &b) {
        return a[1] < b[1];
    });

    multiset<int> ms; // stores when members are free
    int count = 0;

    for (auto &a : arr) {
        int start = a[0];
        int end = a[1];

        // Find member who is free before movie starts
        auto up = ms.upper_bound(start);
        if (up != ms.begin()) {
            --up;
            ms.erase(up);
            ms.insert(end);
            count++;
        } else if (ms.size() < k) {
            // If members still available, assign this movie
            ms.insert(end);
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
