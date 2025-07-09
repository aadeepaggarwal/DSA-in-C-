#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n+1,1);
    int ans=1;
    for(int i=n-2;i>=0;i--){
        if(arr[i+1]<arr[i]){
            dp[i]=dp[i+1]+1;
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}