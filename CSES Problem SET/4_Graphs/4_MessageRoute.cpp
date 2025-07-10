#include <bits/stdc++.h>
using namespace std;
// same find shortest path between 2 nodes,
// do bfs from 1st to nth node

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1), distance(n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    distance[1] = 1; // Path length starts from 1 (node 1 itself)
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto e : graph[x]) {
            if (!visited[e]) {
                visited[e] = true;
                distance[e] = distance[x] + 1;
                parent[e] = x;
                q.push(e);
            }
        }
    }
    if (!visited[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    // Reconstruct path
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";
    return 0;
}