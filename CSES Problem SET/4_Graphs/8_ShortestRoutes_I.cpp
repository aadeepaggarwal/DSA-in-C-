#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int,vector<pair<int,int>>>graph;
    for (int i = 0; i < m; i++)
    {
        int a, b,val;
        cin >> a >> b>>val;
        graph[a].push_back({b,val});
        
    }
    vector<int> team(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;

   
    return 0;
}