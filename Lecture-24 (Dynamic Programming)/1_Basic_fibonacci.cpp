#include <iostream>
#include <vector>
using namespace std;
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}
int dp_fibo_top_bottom(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return dp[n] = n;// way of writing dp[n]=n; and then return n;
    }

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = dp_fibo_top_bottom(n - 1, dp) + dp_fibo_top_bottom(n - 2, dp);
}
int dp_fibo_bottom_up(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << dp_fibo_top_bottom(n, dp) << endl;
    cout << dp_fibo_bottom_up(n) << endl;
    cout << fibo(n) << endl;

    return 0;
}