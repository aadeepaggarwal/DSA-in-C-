#include <bits/stdc++.h>
using namespace std;
// cycle detection, run dfs , if visited node revisit mark true cycle
bool dfs(int node, int parent, const vector<vector<int>>& graph, vector<int>& visited, vector<int>& parent_arr, int& cycle_start, int& cycle_end) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        if (!visited[neighbor]) {
            parent_arr[neighbor] = node;
            if (dfs(neighbor, node, graph, visited, parent_arr, cycle_start, cycle_end)) return true;
        } else {
            // Found a cycle
            cycle_start = neighbor;
            cycle_end = node;
            return true;
        }
    }
    return false;
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
    vector<int> visited(n + 1, 0), parent_arr(n + 1, -1);
    int cycle_start = -1, cycle_end = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited, parent_arr, cycle_start, cycle_end)) break;
        }
    }
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent_arr[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
    return 0;
}