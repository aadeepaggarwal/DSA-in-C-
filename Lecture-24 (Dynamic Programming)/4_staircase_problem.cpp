#include <iostream>
#include <cstring>
using namespace std;
int staircase(int n,int k){
    if(n==0) return 1;
    if(n<0) return 0;

    int ans=0;
    for (int i = 1; i <=k; i++)
    {
        ans+=staircase(n-i,k);
    }
    return ans;
}
int staircase_top_down(int n,int k,int dp[]){
    if(n==0) return dp[n]=1;// store before return
    if(n<0) return 0;
// check before calculation
    if(dp[n]!=-1) return dp[n];

    int ans=0;
    for (int i = 1; i <=k; i++)
    {
        ans+=staircase_top_down(n-i,k,dp);
    }
    return dp[n]=ans;// store before printing
}
int staircase_bottom_up(int n,int k){
    int dp[10000];
    dp[0]=1;

    for (int i = 1; i <= n; i++)// to put value at every index of array till n
    {   int ans=0;
        for (int j=1; j<=k; j++)// to take the sum of previous k digits of array if that index exists
        {
            if (i-j>=0)// check if index exists or not
            {
                ans+=dp[i-j];// add it
            }
            
        }
        dp[i]=ans;// store it
    }
    return dp[n];// return it
}
int staircase_bottom_up_in_less_time(int n,int k){
    int dp[10000];
    dp[0]=1;
    dp[1]=1;// yaha ye bhi karna padega initialize
    for (int i =2; i <= n; i++)
    {
        dp[i]=2*dp[i-1]-(i-1-k>=0 ? dp[dp[i-k-1]]:0);
    }
    
    
    return dp[n];// return it
}

int main() {
    int n,k;
    cin>>n>>k;
    int dp[100000];
    memset(dp,-1,sizeof(dp));// initialize array with all 0s

    cout<<staircase_top_down(n,k,dp)<<endl;
    cout<<staircase_bottom_up(n,k)<<endl;
    cout<<staircase_bottom_up_in_less_time(n,k)<<endl;
    cout<<staircase(n,k)<<endl;
    
    
    return 0;
}