#include <bits/stdc++.h>
using namespace std;

// Define possible knight moves
const vector<pair<int, int>> knightMoves = {
    {-2, -1}, {-2, 1}, {1, -2}, {-1, -2},
    {1, 2}, {-1, 2}, {2, -1}, {2, 1}
};

vector<vector<int>> minKnightMoves(int n) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Start from (0,0)
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        // Try all possible moves
        for (const auto& move : knightMoves) {
            int nx = x + move.first;
            int ny = y + move.second;

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && 
                dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Convert unreachable positions to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                dist[i][j] = -1;
            }
        }
    }

    return dist;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans = minKnightMoves(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
