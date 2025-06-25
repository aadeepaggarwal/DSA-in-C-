#include <bits/stdc++.h>
using namespace std;
int ans=0;
#define MOD (int)(1e9+7)
int solve(vector<long long>&dp,long long n){
    // base case
    if(n==0){
        
        return 1;
    }
    if(n<0)return 0;
    // recursive case
    if(dp[n]!=-1){
        return dp[n];
    }
    long long ways=0;
    for(int i=1;i<=6;i++){
        ways+= solve(dp,n-i);
    }
    return dp[n]=ways;

}
int main() {
    long long n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    vector<long long>dp(n+1,0);
    //cout<<solve(dp,n); // ye hai top down

    // bottom up
    // see dp[n] means n sum pe pahuchne ke tareeke which is dp[n-1,n-2,n-3....n-6] ka sum kyonki dice mein 6 options hote hain
    dp[0]=1;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<7;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n];
    return 0;
}