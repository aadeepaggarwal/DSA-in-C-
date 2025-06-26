#include <bits/stdc++.h>
using namespace std;

vector<int> digits(int n){
    vector<int> ans;
    while (n){
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}

int solve(int n, vector<int>& dp){
    // base case
    if(n == 0) return 0;

    // memoization check
    if(dp[n] != -1) return dp[n];

    vector<int> dig = digits(n);
    int ans = INT_MAX;

    for(auto x : dig){
        if(x > 0 && n - x >= 0){
            ans = min(ans, 1 + solve(n - x, dp));
        }
    }

    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;
    // top down
    // vector<int> dp(n + 1, -1);
    // cout << solve(n, dp);


    // bottom up
    vector<int> dp2(n + 1, INT_MAX);
    dp2[0] = 0; // Base case: 0 steps to reduce 0 to 0

    for(int i = 1; i <= n; i++){
        vector<int> dig = digits(i);
        for(auto x : dig){
            if(x > 0 && i - x >= 0){
                dp2[i] = min(dp2[i], 1 + dp2[i - x]);
            }
        }
    }
    cout << dp2[n];
    return 0;
}
