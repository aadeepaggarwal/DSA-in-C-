#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&coins, vector<int>&dp, int val){
    // base case

    if(val==0)return 0;
    if(val<0)return INT_MAX;
    
    // recursive case
    if(dp[val]!=-1){
        return dp[val];
    }
    int ans=INT_MAX;
    for(auto x: coins){
        int res=solve(coins,dp,val-x);
        if(res!=INT_MAX){
            ans=min(ans,1+res);
        }
    }
    return dp[val]=ans;
}
int main() {
    int n,val;cin>>n>>val;
    vector<int>coins(n);
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    vector<int>dp(val+1, INT_MAX);
    // int ans=solve(coins,dp,val);
    // cout<<(ans==INT_MAX? -1:ans);
    dp[0]=0;
    for(int i=1;i<=val;i++){
        int ans=INT_MAX;
        for(auto x: coins){
            if(i-x>=0 and dp[i-x]!=INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - x]);
            }
        }
        
    }
    if (dp[val] == INT_MAX) {
        cout << -1;
    } else {
        cout << dp[val];
    }
    return 0;
}