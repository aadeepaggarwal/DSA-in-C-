#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    map<int, int> remainderCount;
    remainderCount[0] = 1;

    long long sum = 0, ans = 0;
    for (int x : arr) {
        sum += x;
        int rem = ((sum % n) + n) % n;  // Handle negative sums
        ans += remainderCount[rem];
        remainderCount[rem]++;
    }

    cout << ans << endl;
    return 0;
}
