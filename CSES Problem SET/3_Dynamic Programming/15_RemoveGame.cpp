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

int n;
const int maxN = 5005;
int arr[maxN];
int dp[maxN][maxN][2];

int res(int start, int end, int player) {
    if (start > end) return 0;

    int &ans = dp[start][end][player];
    if (ans != -1) return ans;

    if (player == 0) {
        ans = max(arr[start] + res(start + 1, end, 1),
                  arr[end] + res(start, end - 1, 1));
    } else {
        ans = min(res(start + 1, end, 0),
                  res(start, end - 1, 0));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << res(1, n, 0) << endl;

    return 0;
}
