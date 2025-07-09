#include <bits/stdc++.h>

using namespace std;
// Function to solve a single test case
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 1. Count the total number of '1's in the string.
    int ones_count = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            ones_count++;
        }
    }

    if (ones_count <= k)
    {
        cout << "Alice\n";
        return;
    }
    if (2 * k <= n)
    {
        cout << "Bob\n";
        return;
    }
    int outside_ones = 0;
    for (int i = 0; i <= n - k - 1; ++i)
    {
        if (s[i] == '1')
        {
            outside_ones++;
        }
    }
    for (int i = k; i < n; ++i)
    {
        if (s[i] == '1')
        {
            outside_ones++;
        }
    }
    if (outside_ones <= k)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}