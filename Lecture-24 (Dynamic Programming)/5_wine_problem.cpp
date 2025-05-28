#include <iostream>
#include <cstring>
using namespace std;
int solve(int *price,int l,int r,int day){
    // base case
    if(l>r) return 0;
    // recursion
    int op1=price[l]*day+ solve(price,l+1,r,day+1);
    int op2=price[r]*day+ solve(price,l,r-1,day+1);// yani ki ek baar l wali ek baar right wali bottle bechke baki bache hue pe day+1 karke call karde kyonki ek din to badh gaya na
    return max(op1,op2);
}
int solve_top_bottom(int *price,int l,int r,int day,int dp[][100]){
    // base case
    if(l>r) return dp[l][r]= 0;
    // recursion
    if (dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    
    int op1=price[l]*day+ solve_top_bottom(price,l+1,r,day+1,dp);
    int op2=price[r]*day+ solve_top_bottom(price,l,r-1,day+1,dp);// yani ki ek baar l wali ek baar right wali bottle bechke baki bache hue pe day+1 karke call karde kyonki ek din to badh gaya na
    return dp[l][r]= max(op1,op2);
}
int solve_bottom_up(int*price,int n){
    int dp[100][100]={0};

    for (int i = n-1; i >= 0; i--)// traverse only on the upper triangular matrix
    {
        for (int j =i ; j < n; j++)
        {
            int day=n-(j-i);
            int op1,op2;
            op1=price[i]*day +(i+1<n? dp[i+1][j]:0);
            op2=price[j]*day +(j-1>=0? dp[i][j-1]:0);// yaha bas check if index exists and if yes then add
            dp[i][j]= max(op1,op2);
        }
        
    }
    return dp[0][n-1];
}
int main() {
    int price[]={2,3,5,1,4};
    int n=sizeof(price)/sizeof(int);

    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<solve(price,0,4,1)<<endl;
    cout<<solve_top_bottom(price,0,4,1,dp)<<endl;
    cout<<solve_bottom_up(price,n);

    return 0;
}