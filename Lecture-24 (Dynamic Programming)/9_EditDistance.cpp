#include <iostream>
#include<cstring>
using namespace std;
int solve(char* a, char*b,int n, int m){
    // base case
    if(m==0) return n;
    if(n==0) return m;
    // recursive case 
    if(a[n-1]==b[m-1]) return solve(a,b,n-1,m-1);
    else{
        int op1,op2,op3;
        op1=solve(a,b,n,m-1);
        op2=solve(a,b,n-1,m-1);
        op3=solve(a,b,n-1,m);
        return 1+ min(op1,min(op2,op3));
    }
    
}
int solve_top_bottom(char* a, char*b,int n, int m,int dp[][100]){
    // base case
    if(m==0) return dp[n][m]= n;
    if(n==0) return dp[n][m]= m;

    if(dp[n][m]!= -1) return dp[n][m];
    // recursive case 
    if(a[n-1]==b[m-1]) return dp[n][m]= solve_top_bottom(a,b,n-1,m-1,dp);
    else{
        int op1,op2,op3;
        op1=solve(a,b,n,m-1);
        op2=solve(a,b,n-1,m-1);
        op3=solve(a,b,n-1,m);
        return dp[n][m]= 1+ min(op1,min(op2,op3));
    }
    
}
int main() {
    char a[]="Saturday";
    char b[]="Sunday";
    cout<< solve(a,b,strlen(a),strlen(b))<<endl;
    int n= strlen(a);
    int m=strlen(b);
    int dp[100][100];
    memset(dp,-1,sizeof dp);
    cout<<solve_top_bottom(a,b,n,m,dp)<<endl;
    return 0;
}