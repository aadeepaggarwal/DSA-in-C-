// #include <iostream>
// #include <vector>
// using namespace std;
// class DSU{
//     vector<int> parent;
//     DSU(int n){
//         parent.resize(n+1);
//         for(int i=0;i<=n;i++){
//             make_Set(i);
//         }
//     }
//     void make_Set(int i){
//         parent[i]=i;
//     }
//     int find_Set(int u){
//         if(u==parent[u]) return u;
//         return find_Set(parent[u]);
//     }
//     void union_set(int u, int v){
//         int leader_u=find_Set(u);
//         int leader_v=find_Set(v);

//         parent[leader_v]=leader_u;
//     }
// };
// int main() {
//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};

int main() {
    int N, M1, M2;
    cin >> N >> M1 >> M2;

    DSU dsu_road(N), dsu_rail(N);

    for (int i = 0; i < M1; i++) {
        int u, v;
        cin >> u >> v;
        dsu_road.unite(u, v);
    }

    for (int i = 0; i < M2; i++) {
        int u, v;
        cin >> u >> v;
        dsu_rail.unite(u, v);
    }

    map<pair<int, int>, int> count_map;
    vector<pair<int, int>> ids(N + 1);

    for (int i = 1; i <= N; i++) {
        int road_id = dsu_road.find(i);
        int rail_id = dsu_rail.find(i);
        ids[i] = {road_id, rail_id};
        count_map[ids[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        cout << count_map[ids[i]] << " ";
    }
    cout << endl;

    return 0;
}