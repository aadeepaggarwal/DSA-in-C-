#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
// basically pehle topological sort kar and ek order bana le
// ab order mein ek ek karke ham aage jayenge and ek dp bana lenge sab nodes ki
// dp[1] means ways to reach node 1 from all its parents
// so whenever we pluck a new node from queue of toposort, we get a way to reach its neighbours
// hence update the dp of neighbours by += dp[par]+1;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}