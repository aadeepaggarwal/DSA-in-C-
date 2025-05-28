#include <iostream>
#include <vector>
using namespace std;
class DSU{
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            make_Set(i);
            size[i]=1;
        }
    }
    void make_Set(int i){
        parent[i]=i;
    }
    int find_Set(int u){
        if(u==parent[u]) return u;
        return parent[u]=find_Set(parent[u]);// to do path compression we store parent directly as the main leader
    }
    void union_set(int u, int v){
        int leader_u=find_Set(u);
        int leader_v=find_Set(v);
        // har baar operation u pe hi karenge isilye agar u bada hai to theek wanra swap karke kaam karlo
        if(size[leader_u]<size[leader_v]) swap(leader_u,leader_v);
        parent[leader_v]=leader_u;
        size[leader_u]+=size[leader_v];// size ke case mein add sizes rank ke case mein do++ if same 
    }
};
int main() {
    return 0;
}