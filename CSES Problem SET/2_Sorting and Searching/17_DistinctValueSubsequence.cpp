// #include <bits/stdc++.h>
// using namespace std;
// int solve(vector<int>&arr, int i, unordered_set<int>&seen,vector<int>&dp){
//     // base case
//     if(i==arr.size()){
//         return dp[i]=0;
//     }
//     // recursive case
//     if(dp[i]!=-1) return dp[i];
//     int op1=0,op2=0;
//     if(!seen.count(arr[i])){
//         seen.insert(arr[i]);
//         op1= 1+solve(arr,i+1,seen,dp);
//         seen.erase(arr[i]);
//     }
//     op2= 0+ solve(arr,i+1,seen,dp);
//     return dp[i]=op1+op2;

// }
// int main() {
//     int n;cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     unordered_set<int>seen;
//     vector<int>dp(n,-1);
//     cout<<solve(arr,0,seen,dp);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    unordered_map<int, int> last;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // empty subsequence

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = (2 * dp[i]) % MOD;

        if (last.count(arr[i])) {
            int j = last[arr[i]];
            dp[i + 1] = (dp[i + 1] - dp[j] + MOD) % MOD;
        }

        last[arr[i]] = i;
    }

    cout << (dp[n] - 1 + MOD) % MOD << "\n"; // exclude empty subsequence
    return 0;
}
