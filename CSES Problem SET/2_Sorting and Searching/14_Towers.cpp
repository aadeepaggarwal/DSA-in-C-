#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> towers;

    for(int i = 0; i < n; i++) {
        // Find first tower whose top > arr[i]
        auto it = upper_bound(towers.begin(), towers.end(), arr[i]);
        if(it == towers.end()) {
            // No tower found, create new one
            towers.push_back(arr[i]);
        } else {
            // Replace top of that tower
            *it = arr[i];
        }
    }

    cout << towers.size() << endl;
    return 0;
}
