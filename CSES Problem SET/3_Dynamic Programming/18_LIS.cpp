// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);

//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     vector<int> dp(n, 1); // dp[i] = length of LIS ending at i

//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (a[j] < a[i]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     int ans = *max_element(dp.begin(), dp.end());
//     cout << ans << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> lis;

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }

    cout << lis.size() << endl;

    return 0;
}
