#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Initialize distance from a node to itself as 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // Read edges and initialize distances
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w); // since the graph is undirected
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dist[a][b] << '\n';
    }

    return 0;
}
