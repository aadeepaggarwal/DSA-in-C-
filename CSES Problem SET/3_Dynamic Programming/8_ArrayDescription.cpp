#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int solve(int prev, int i, vector<int>& arr, int n, int mx, vector<vector<int>>& dp) {
    // Base case
    if (i == n) return 1;
    if (prev < 1 || prev > mx) return 0;
    if (arr[i] != 0 && abs(prev - arr[i]) > 1) return 0;

    // Memoization check
    if (dp[i][prev] != -1) return dp[i][prev];

    int ans = 0;

    if (arr[i] == 0) {
        // Try prev - 1, prev, prev + 1 within bounds
        for (int diff = -1; diff <= 1; diff++) {
            int nextVal = prev + diff;
            if (nextVal >= 1 && nextVal <= mx) {
                ans = (ans + solve(nextVal, i + 1, arr, n, mx, dp)) % MOD;
            }
        }
    } else {
        if (abs(prev - arr[i]) <= 1) {
            ans = solve(arr[i], i + 1, arr, n, mx, dp) % MOD;
        }
    }

    return dp[i][prev] = ans;
}

int main() {
    int n, mx;
    cin >> n >> mx;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(mx + 2, -1));

    int ans = 0;
    if (arr[0] != 0) {
        ans = solve(arr[0], 1, arr, n, mx, dp) % MOD;
    } else {
        for (int val = 1; val <= mx; val++) {
            ans = (ans + solve(val, 1, arr, n, mx, dp)) % MOD;
        }
    }

    cout << ans;
    return 0;
}
