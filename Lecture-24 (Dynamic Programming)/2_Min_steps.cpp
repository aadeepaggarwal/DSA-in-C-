#include <iostream>
#include <climits>
#include <vector>
using namespace std;
////////////////// bada recursion ka 3^n wala tareeka/////////////////
int minsteps(int n){// min steps to convert n to 1 we have 3 options - N-1,N/2,N/3 with %2 or%3 respectively condition
    if (n==1)
    {
        return 0;
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    op1=minsteps(n-1);
    if (n%2==0)
    {
        op2=minsteps(n/2);
    }
    if (n%3==0)
    {
        op3=minsteps(n/3);
    }
    
    return min(op1,min(op2,op3))+1;
}
                        /// ye dp hai ab O(N) ki ///

int minsteps_topdown(int n, vector<int>& dp){
    if (n==1)
    {
        return dp[n]=0;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    op1=minsteps_topdown(n-1,dp);
    if (n%2==0)
    {
        op2=minsteps_topdown(n/2,dp);
    }
    if (n%3==0)
    {
        op3=minsteps_topdown(n/3,dp);
    }
    
    return dp[n]=min(op1,min(op2,op3))+1;// yaha se minimum wala return karwa rahe hain
}

int minsteps_bottomup(int n){
    vector<int> dp(n+1,-1);
    dp[1]=0;
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    for (int i = 2; i <=n; i++)
    {
        
        op1= dp[i-1];
        if (i%2==0)
        {
           op2=dp[i/2];
        }
         if (i%3==0)
        {
           op2=dp[i/3];
        }
        dp[i]=min(op1,min(op1,op2))+1;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);

    cout<<minsteps_topdown(n,dp)<<endl;
    cout<<minsteps_bottomup(n)<<endl;
    cout<<minsteps(n)<<endl;
    // at 900 input dp wala dedega ans but normal nai dega
    return 0;
}