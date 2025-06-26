#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD (int)(1e9 + 7)

signed main() {

    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (auto &c : coins) {
        cin >> c;
    }

    vector<int> dp(sum + 1);
    dp[0] = 1;

    for (auto c : coins) {
        for (int i = 1; i <= sum; i++) {
            if ((i - c) >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }

    cout << dp[sum];
    return 0;
}
