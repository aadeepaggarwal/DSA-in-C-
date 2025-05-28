#include <iostream>
#include<climits>
#include <cstring>
using namespace std;
int solve(int *price, int *weight,int capacity, int n){
    // base case
    if(capacity ==0 || n==0){
        return 0;
    }
    // recursive case
    int op1=INT_MIN,op2=INT_MIN;
    if (capacity>=weight[n-1])// means weight ko we can add in current capacity so add it and go ahead
    {
        op1= price[n-1]+ solve(price,weight, capacity-weight[n-1],n-1);

    }
    op2= 0 + solve(price, weight, capacity, n-1);// agar weight nahi aa sakta to move ahead drop this element
    return max(op1,op2);
    
}
int solve_top_bottom(int *price, int *weight,int capacity, int n, int dp[][100]){
    // base case
    if(capacity ==0 || n==0){
        return dp[n][capacity]= 0;
    }

    if(dp[n][capacity]!= -1) return dp[n][capacity];
    // recursive case
    int op1=INT_MIN,op2=INT_MIN;
    if (capacity>=weight[n-1])// means weight ko we can add in current capacity so add it and go ahead
    {
        op1= price[n-1]+ solve_top_bottom(price,weight, capacity-weight[n-1],n-1,dp);

    }
    op2= 0 + solve_top_bottom(price, weight, capacity, n-1,dp);// agar weight nahi aa sakta to move ahead drop this element
    return dp[n][capacity]= max(op1,op2);
    
}
int solve_bottom_up(int *price, int *weight, int capacity, int N){
    int dp[100][100]={0};
    for (int n = 1; n <=N; n++)
    {
        for (int cap = 1; cap <= capacity; cap++)
        {
            int op1=INT_MIN, op2=INT_MIN;
            if (cap>=weight[n-1])
            {
                op1= price[n-1]+ dp[n-1][cap- weight[n-1]];
            }
            op2= 0+dp[n-1][cap];
            dp[n][cap]=max(op1,op2);
        }
        
    }
    for (int n = 0; n <=N; n++)
    {
        for (int cap = 0; cap <= capacity; cap++){
            cout<<dp[n][cap]<<" ";
        }
        cout<<endl;
    }
    return dp[N][capacity];
}
int main() {
    int price[]={4,5,6,3};
    int weight[]={2,4,3,1};
    int n=sizeof(price)/sizeof(int);
    int capacity=5;
    //cout<<solve(price,weight,capacity,n);

    int dp[100][100];
    memset(dp,-1,sizeof dp);

    //cout<< endl<< solve_top_bottom(price,weight,capacity,n,dp);
    cout<<endl<<solve_bottom_up(price,weight,capacity,n);
    return 0;
}