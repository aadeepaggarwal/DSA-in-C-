#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD (int)(1e9 + 7)

int fastpow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

#define inv(a) fastpow(a, MOD - 2)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << endl;
    } else {
        int N = sum / 2;
        vector<int> dp(N + 1);
        dp[0] = 1;

        // let's iterate over all the coins
        for (int i = 1; i <= n; i++) {
            // let's iterate over the sums
            for (int j = N; j > 0; j--) {
                // if can use this coin
                if (j - i >= 0) {
                    dp[j] = (dp[j] + dp[j - i]) % MOD;
                }
            }
        }
        cout << (dp[N] * inv(2)) % MOD << endl;
    }

    return 0;
}
