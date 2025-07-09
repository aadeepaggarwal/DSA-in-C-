#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> team(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            team[i] = 1;
            visited[i] = true;
            while (!q.empty())
            {
                int x = q.front();
                int curr = team[x];
                q.pop();
                for (auto e : graph[x])
                {
                    if (!visited[e])
                    {
                        visited[e] = true;
                        if (team[e] == 0)
                        {
                            team[e] = curr == 1 ? 2 : 1;
                        }
                        q.push(e);
                    }
                    else if (team[e] == curr)
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i < team.size(); i++)
    {
        cout << team[i] << " ";
    }
    return 0;
}