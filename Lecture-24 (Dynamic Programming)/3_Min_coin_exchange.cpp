#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//////////// normal recursion////////////
int solve(int amount, int *coins,int n){
    // base case
    if(amount==0){
        return 0;
    }
    // recurisve case
    int ans=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (amount>=coins[i])
        {
            int small_amount=amount-coins[i];
            int chhotaans=solve(small_amount,coins,n);
            if (chhotaans!=INT_MAX)
            {
              ans=min(ans,chhotaans+1);  
            }
            
        }
        
    }
    return ans;
}
/////// dp top to bottom/////////////
int solve_top_bottom(int amount, int *coins,int n, vector<int> &dp){
    
    // base case
    if(amount==0){
        return dp[amount]=0;
    }
    // recurisve case
    if (dp[amount]!=-1)
    {
        return dp[amount];
    }
    
    int ans=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (amount>=coins[i])
        {
            int small_amount=amount-coins[i];
            int chhotaans=solve_top_bottom(small_amount,coins,n,dp);
            if (chhotaans!=INT_MAX)
            {
              ans=min(ans,chhotaans+1);  
            }
            
        }
        
    }
    return dp[amount]=ans;
}
int solve_bottom_top(int totalAmount, int *coins, int n) {
	vector<int> dp(totalAmount + 1, INT_MAX);

	dp[0] = 0;

	for (int amount = 1; amount <= totalAmount; ++amount)
	{
		for (int i = 0; i < n; ++i)
		{
			if (amount >= coins[i]) {
				int chotiAmount = amount - coins[i];
				if (dp[chotiAmount] != INT_MAX) {
					dp[amount] = min(dp[amount], dp[chotiAmount] + 1);
				}
			}
		}
	}

	for (int i = 0; i <= totalAmount; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[totalAmount];
}
int main() {
    int n;
    cout<<"Enter the total coins\n";
    cin>>n;
    int* coins=new int[n];
    for (int i = 0; i < n; i++)
    {   cout<<"Enter the coin face value: ";
        cin>>coins[i];   
    }
    int amount;
    cout<<"Enter the amount: \n";
    cin>>amount;
    vector<int> dp(amount+1,-1);
   //cout<< solve(amount,coins,n)<<endl;
  // cout<< solve_top_bottom(amount,coins,n,dp)<<endl;
   solve_bottom_top(amount,coins,n);

    return 0;
}