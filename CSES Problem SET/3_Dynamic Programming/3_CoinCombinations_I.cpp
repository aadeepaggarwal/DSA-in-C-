#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> coins(n);
    for (long long i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for (long long i = 1; i <= x; i++) {
        for (auto val : coins) {
            if (i - val >= 0) {
                dp[i] =(dp[i]+ dp[i - val])%MOD;
            }
        }
    }

    cout << dp[x];
    return 0;
}
