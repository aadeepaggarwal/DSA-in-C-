#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>>& pricespages, vector<vector<int>>& dp, int val, int i){
    // base case
    if (i == pricespages.size()) return 0;
    if (val < 0) return INT_MIN;
    if (val == 0) return 0;

    // memoization
    if (dp[i][val] != -1) return dp[i][val];

    int op1 = INT_MIN;
    if (val - pricespages[i].first >= 0)
        op1 = pricespages[i].second + solve(pricespages, dp, val - pricespages[i].first, i + 1);

    int op2 = solve(pricespages, dp, val, i + 1);

    return dp[i][val] = max(op1, op2);
}

int main() {
    ////                    TOP TO BOTTOM
    // int n, val;
    // cin >> n >> val;
    // vector<pair<int, int>> pricespages(n);
    
    // for (int i = 0; i < n; i++) {
    //     cin >> pricespages[i].first;  // price
    // }
    // for (int i = 0; i < n; i++) {
    //     cin >> pricespages[i].second; // pages
    // }

    // vector<vector<int>> dp(n, vector<int>(val + 1, -1));
    // cout << solve(pricespages, dp, val, 0);


    ///                 BOTTOM UP
     int n, val;
    cin >> n >> val;
    vector<int> price(n), pages(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i];  // Har book ki price le rahe hain
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];  // Har book ke pages le rahe hain
    }

    // dp[j] ka matlab hai:
    // "agar mere paas total paisa j tak kharch karne ki permission hai,
    // to maximum kitne pages le sakta hoon"

    vector<int> dp(val + 1, 0);  // Sabhi initial 0, kyunki shuru mein koi pages nahi

    for (int i = 0; i < n; i++) {  // Har book ke liye
        // Reverse loop isliye lagate hain taaki same iteration mein updated value ko dubara use na karen
        // Agar forward loop lagaya toh updated value khud ke upar effect karegi, jo galat hoga
        for (int j = val; j >= price[i]; j--) {
            // Do option hamesha:
            // 1. Book nahi lena
            // 2. Book lena (agar paisa bacha hai)
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    // dp[val] mein final answer hoga, maximum pages jo le sakte hain given paisa mein
    cout << dp[val] << endl;

    return 0;
    
}
