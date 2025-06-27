#include <bits/stdc++.h>
using namespace std;

string solve(vector<vector<char>>& arr, int i, int j, int n, vector<vector<string>>&dp) {
    // Base Case
    if (i == n - 1 && j == n - 1) {
        return string(1, arr[i][j]);
    }

    // Agar grid ke bahar chale gaye
    if (i >= n || j >= n) {
        return "{";
    }

    // DP check
    if (dp[i][j] != "@") return dp[i][j];

    // Right aur Down dono paths ke answers
    string right = solve(arr, i, j + 1, n, dp);
    string down = solve(arr, i + 1, j, n, dp);

    // Minimum path
    dp[i][j] = arr[i][j] + min(right, down);

    return dp[i][j];
}

int main() {
    // int n;
    // cin >> n;
    // vector<vector<char>> arr(n, vector<char>(n));
    // vector<vector<string>> dp(n, vector<string>(n, "{}")); // "{ ya @"" ka matlab abhi calculate nahi hua

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> arr[i][j];

    // // cout << solve(arr, 0, 0, n, dp) << endl;

    // // bottom up

    //  for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {

    //         // Starting cell
    //         if (i == 0 && j == 0) {
    //             dp[i][j] = string(1, arr[i][j]);
    //         } 
    //         else {
    //             string fromTop = (i > 0) ? dp[i - 1][j] : "{";
    //             string fromLeft = (j > 0) ? dp[i][j - 1] : "{";

    //             dp[i][j] = min(fromTop, fromLeft) + arr[i][j];
    //         }
    //     }
    // }

    // cout << dp[n - 1][n - 1] << endl;

    // return 0;


    #include <bits/stdc++.h>
using namespace std;


    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<string>> dp(n, vector<string>(n));

    // Input grid
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // Fill DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {
                dp[i][j] = string(1, grid[i][j]); // Starting cell
            } 
            else {
                string fromTop = (i > 0) ? dp[i - 1][j] : "{";
                string fromLeft = (j > 0) ? dp[i][j - 1] : "{";

                dp[i][j] = min(fromTop, fromLeft) + grid[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}


