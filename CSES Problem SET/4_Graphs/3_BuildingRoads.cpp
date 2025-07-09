#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

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
    vector<int> reps;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(graph, visited, i);
        }
    }
    cout << reps.size() - 1 << "\n";
    for (int i = 0; i + 1 < reps.size(); i++) {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }
    return 0;
}