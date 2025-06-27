#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum_total = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        sum_total += coins[i];
    }

    vector<bool> dp(sum_total + 1, false);
    dp[0] = true; // sum 0 always possible

    for (int coin : coins) {
        for (int s = sum_total; s >= coin; s--) {
            if (dp[s - coin]) {
                dp[s] = true;
            }
        }
    }

    vector<int> sums;
    for (int s = 1; s <= sum_total; s++) {
        if (dp[s]) {
            sums.push_back(s);
        }
    }

    cout << sums.size() << "\n";
    for (int s : sums) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}
