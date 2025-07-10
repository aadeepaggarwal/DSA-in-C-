#include <bits/stdc++.h>
using namespace std;
// djikstra
// use a heap

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long val;
        cin >> a >> b >> val;
        graph[a].push_back({b, val});
    }
    vector<long long> dist(n + 1, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop();
        if (d > dist[x]) continue;
        for (auto e : graph[x]) {
            int to = e.first;
            long long w = e.second;
            if (dist[to] > dist[x] + w) {
                dist[to] = dist[x] + w;
                pq.push({dist[to], to});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}