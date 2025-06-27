#include <bits/stdc++.h>
using namespace std;

// Yahan hum int ko unsigned int bana rahe hain taaki large numbers handle ho sake
#define int unsigned int
#define MOD (int)(1e9 + 7)

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // Maximum size set kar diya hai
    int N = 1e6 + 5;

    // dp[i][0] = i length ki sequence, jiska last block divided hai
    // dp[i][1] = i length ki sequence, jiska last block blank hai
    int dp[N][2];
    memset(dp, 0, sizeof dp);

    // Base case: length 1 ki sequence banane ka 1 hi tarika hai dono ke liye
    // 1 length ke liye agar divided hai to dp[1][0] = 1
    // 1 length ke liye agar blank hai to dp[1][1] = 1
    dp[1][0] = dp[1][1] = 1;

    // Yahan se dp build kar rahe hain 2 se lekar N tak
    for (int i = 2; i < N; i++) {

        // Jab last block divided (0) hai
        // 0 se 5 option bante hain: 4 blank + 1 divided => total 4 possibilities (4 blank create karega)
        // Isliye 4 * dp[i - 1][0] likha hai
        // Aur 1 possibility yeh hai ki pehle blank tha, usse bhi divided bana sakte hain => dp[i - 1][1]
        dp[i][0] = (4 * dp[i - 1][0] % MOD + dp[i - 1][1]) % MOD;

        // Jab last block blank (1) hai
        // 1 se 3 options bante hain: 2 blank + 1 divided => total 2 possibilities (2 blank create karega)
        // Aur 1 possibility hai ki pehle divided tha, usse blank bana sakte hain => dp[i - 1][0]
        dp[i][1] = (2 * dp[i - 1][1] % MOD + dp[i - 1][0]) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        // Final answer: total divided + total blank sequences of length n
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }

    return 0;
}
