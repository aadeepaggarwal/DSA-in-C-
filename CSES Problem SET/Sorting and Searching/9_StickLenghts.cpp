#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int median = arr[n / 2]; // For even n, this is one of the possible medians

    long long total = 0;
    for(int i = 0; i < n; i++) {
        total += abs(arr[i] - median);
    }

    cout << total << endl;
    return 0;
}
