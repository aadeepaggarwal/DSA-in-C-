#include <bits/stdc++.h>
using namespace std;

#define MOD (int)(1e9 + 7)

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // Rectangle ki dimensions input
    int a, b;
    cin >> a >> b;

    // dp[i][j] = i x j rectangle ko minimum kitne cuts mein squares mein tod sakte hain
    int dp[a + 1][b + 1];

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {

            // Pehle assume kar lo ki har rectangle ko alag alag cut karna padhega
            dp[i][j] = INT_MAX;

            // Agar already square hai to koi cut nahi chahiye
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            // Horizontal cuts laga sakte hain
            // i x j rectangle mein row wise cut lagao 1 se lekar i-1 tak sab possibilities try karo
            for (int x = 1; x < i; x++) {
                // Upar ke hisse ka dp + neeche ke hisse ka dp + 1 (cut lagane ka)
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j] + 1);
            }

            // Vertical cuts laga sakte hain
            // i x j rectangle mein column wise cut lagao 1 se lekar j-1 tak sab possibilities try karo
            for (int x = 1; x < j; x++) {
                // Baayen hisse ka dp + daayen hisse ka dp + 1 (cut lagane ka)
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j - x] + 1);
            }
        }
    }

    // Final answer: minimum cuts to convert a x b rectangle to squares
    cout << dp[a][b] << endl;

    return 0;
}
