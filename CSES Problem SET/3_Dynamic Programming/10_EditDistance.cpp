#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j, int n, int m, vector<vector<int>>& dp) {
    // Base cases
    if (i == n) return m - j;  // Remaining characters of b need to be inserted
    if (j == m) return n - i;  // Remaining characters of a need to be deleted

    // Memoization check
    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) {
        // Characters match, move ahead
        return dp[i][j] = solve(a, b, i + 1, j + 1, n, m, dp);
    } else {
        // Three operations: insert, delete, replace
        int insertOp = 1 + solve(a, b, i, j + 1, n, m, dp);   // Insert character into a
        int deleteOp = 1 + solve(a, b, i + 1, j, n, m, dp);   // Delete character from a
        int replaceOp = 1 + solve(a, b, i + 1, j + 1, n, m, dp);  // Replace character

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve(a, b, 0, 0, n, m, dp) << endl;

    return 0;
}
