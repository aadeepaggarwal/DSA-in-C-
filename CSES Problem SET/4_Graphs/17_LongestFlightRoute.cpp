#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
const long long NEG_INF = LLONG_MIN;

int n, m;
vector<int> adj[maxN];       // Adjacency list
vector<int> visited, res;    // For topological sort
long long dist[maxN];        // Distance array
int parent[maxN];            // To reconstruct the path

// Topological Sort using DFS
void topoDFS(int v) {
    visited[v] = true;
    for (int a : adj[v]) {
        if (!visited[a]) {
            topoDFS(a);
        }
    }
    res.push_back(v);
}

vector<int> topoSort() {
    visited.assign(n + 5, false);
    res.clear();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topoDFS(i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// Reconstruct path from 1 to n using parent[]
vector<int> reconstructPath() {
    vector<int> path;
    if (dist[n] == NEG_INF) return {};  // no path
    for (int at = n; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Step 1: Toposort
    vector<int> topo = topoSort();

    // Step 2: Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = NEG_INF;
        parent[i] = -1;
    }
    dist[1] = 0;

    // Step 3: Relax in topological order
    for (int u : topo) {
        if (dist[u] == NEG_INF) continue;
        for (int v : adj[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    // Step 4: Output the result
    vector<int> path = reconstructPath();
    if (path.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << path.size() << "\n";
        for (int v : path) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}

// this new code if other problem to give longest flight trip
// again topo-sort karle
// iss bar add karne ki jagah max wala store karle

// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// unordered_map<int, vector<int>> adj;

// int main() {
//     cin >> n >> m;
//     vector<int> indegree(n + 1, 0);
//     for (int i = 0; i < m; i++) {
//         int a, b; cin >> a >> b;
//         adj[a].push_back(b);
//         indegree[b]++;
//     }

//     vector<int> dp(n + 1, INT_MIN); // dp[i]: max path length from 1 to i
//     dp[1] = 0;
//     queue<int> q;
//     for (int i = 1; i <= n; i++)
//         if (indegree[i] == 0) q.push(i);

//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         for (int v : adj[u]) {
//             if (dp[u] != INT_MIN)
//                 dp[v] = max(dp[v], dp[u] + 1);
//             indegree[v]--;
//             if (indegree[v] == 0) q.push(v);
//         }
//     }

//     if (dp[n] == INT_MIN) {
//         cout << "IMPOSSIBLE\n";
//     } else {
//         // Reconstruct path
//         vector<int> path;
//         int cur = n;
//         while (cur != 1) {
//             path.push_back(cur);
//             int found = 0;
//             for (int u = 1; u <= n; u++) {
//                 for (int v : adj[u]) {
//                     if (v == cur && dp[u] == dp[cur] - 1) {
//                         cur = u;
//                         found = 1;
//                         break;
//                     }
//                 }
//                 if (found) break;
//             }
//             if (!found) break;
//         }
//         path.push_back(1);
//         reverse(path.begin(), path.end());
//         cout << path.size() << "\n";
//         for (int v : path) cout << v << " ";
//         cout << "\n";
//     }
//     return 0;
// }