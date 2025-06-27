#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr1, vector<int>& arr2, int i, int j, vector<vector<int>>& dp, int n, int m) {
    // base case: agar koi bhi array pura khatam ho gaya to LCS length 0
    if (i == n || j == m) return 0;

    // memoization check
    if (dp[i][j] != -1) return dp[i][j];

    int op1 = INT_MIN, op2 = INT_MIN;

    if (arr1[i] == arr2[j]) {
        // agar dono array ke element same hain to LCS mein include karenge
        return dp[i][j] = 1 + solve(arr1, arr2, i + 1, j + 1, dp, n, m);
    } else {
        // nahi to ek baar pehla array aage badha ke dekhenge
        op1 = solve(arr1, arr2, i + 1, j, dp, n, m);
        // ya doosra array aage badha ke dekhenge
        op2 = solve(arr1, arr2, i, j + 1, dp, n, m);
    }

    return dp[i][j] = max(op1, op2);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // dp[n+1][m+1] lena sahi hota hai kyunki 0 based indexing ke saath out of bound avoid hoga
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int ans = solve(arr1, arr2, 0, 0, dp, n, m);
    cout << ans << endl;

    // LCS print karne ke liye reverse traversal kar rahe hain
    vector<int> an;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            // agar dono same hain to LCS mein add karenge
            an.push_back(arr1[i]);
            i++;
            j++;
        } else if (i + 1 < n && (j + 1 >= m || dp[i + 1][j] >= dp[i][j + 1])) {
            // agar aage badha ke LCS bada mil raha hai to pehla array aage badhao
            i++;
        } else {
            // nahi to doosra array aage badhao
            j++;
        }
    }

    // sequence reverse print karni ki zarurat nahi, kyunki upar se correct banayi hai
    for (int k = 0; k < an.size(); k++) {
        cout << an[k] << " ";
    }
    cout << endl;

    return 0;
}
