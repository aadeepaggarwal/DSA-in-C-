#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
int solve(vector<vector<char>> &grid, int i, int j, vector<vector<int>>& dp, int n){
    // base case
    if(i == n - 1 && j == n - 1){
        return 1;
    }

    // memoization check
    if(dp[i][j] != -1) return dp[i][j];

    int op1 = 0, op2 = 0;
    if(i + 1 < n && grid[i + 1][j] != '*') op1 = solve(grid, i + 1, j, dp, n);
    if(j + 1 < n && grid[i][j + 1] != '*') op2 = solve(grid, i, j + 1, dp, n);

    return dp[i][j] = op1 + op2;
}

int main() {
    // int n;
    // cin >> n;
    // vector<vector<char>> grid(n, vector<char>(n));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cin >> grid[i][j];
    //     }
    // }

    // //vector<vector<int>> dp(n, vector<int>(n, -1));

    // // If starting cell itself is blocked, answer is 0
    // if(grid[0][0] == '*' || grid[n - 1][n - 1] == '*'){
    //     cout << 0;
    // }
    // // else{
    // //     cout << solve(grid, 0, 0, dp, n)%MOD;
    // // }

    // vector<vector<int>> dp2(n+1, vector<int>(n+1, 0));
    // dp2[1][1]=1;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         if (grid[i-1][j-1] == '*') continue;

    //         if (i > 1) dp2[i][j] = (dp2[i][j] + dp2[i - 1][j]) % MOD;
    //         if (j > 1) dp2[i][j] = (dp2[i][j] + dp2[i][j - 1]) % MOD;

    //     }
    // }
    // cout<<dp2[n][n];
    // return 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    char mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    if (mat[0][0] == '.')
        dp[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == '*') continue;

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
