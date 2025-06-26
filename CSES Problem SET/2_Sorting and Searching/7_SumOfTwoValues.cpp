#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, val;
    cin >> n >> val;

    vector<pair<int, int>> arr(n);  // {value, index}
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i + 1};  // 1-based index as per many CP problems
    }

    sort(arr.begin(), arr.end());

    int pt1 = 0, pt2 = n - 1;
    while (pt1 < pt2) {
        int sum = arr[pt1].first + arr[pt2].first;
        if (sum == val) {
            cout << arr[pt1].second << " " << arr[pt2].second << '\n';
            return 0;
        } else if (sum < val) {
            pt1++;
        } else {
            pt2--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
