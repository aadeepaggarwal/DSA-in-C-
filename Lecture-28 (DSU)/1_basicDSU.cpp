#include <iostream>
#include <vector>
using namespace std;
class DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            make_Set(i);
        }
    }
    void make_Set(int i){
        parent[i]=i;
    }
    int find_Set(int u){
        if(u==parent[u]) return u;
        return find_Set(parent[u]);
    }
    void union_set(int u, int v){
        int leader_u=find_Set(u);
        int leader_v=find_Set(v);

        parent[leader_v]=leader_u;
    }
};
int main() {
    return 0;
}