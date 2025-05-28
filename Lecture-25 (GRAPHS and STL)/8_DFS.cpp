#include <iostream>
#include<unordered_map>// for unordered map
#include<map>// for ordered map
#include<list>
#include<queue>

using namespace std;
// for Graph <d_type, d_type> format we can use template
// template<typename T, typename U> 
// if U and V are same so we can use only one T/U everywhere 
template<typename T> 
class Graph{
    public:
    map<T,list<T>> adj;// make ordered map iss bar
    void AddEdge(T u, T v, bool Bidirectional=true){
        adj[u].push_back(v);
        if(Bidirectional){
            adj[v].push_back(u);
        }
    }
// iss function se hamein neeche src and map pass karwana padega alag se but if dont want that then we can make a function alag se for that and call ye neeche wala function as helper
   void DFS(T src, unordered_map<T, bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        // recursive case
        for(auto child: adj[src]){
            if(!visited[child]){
                DFS(child,visited);
            }
        }
   }
    void DFS_helper(T src, unordered_map<T, bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        // recursive case
        for(auto child: adj[src]){
            if(!visited[child]){
                DFS_helper(child,visited);
            }// base case yaha already ye hai ki jab sab visited hain and we went to all the nodes neighbour of rc to bahar aaja loop se and khatam
        }
   }
   void dfs(T src){
    unordered_map<T, bool> visited;
    DFS_helper(src,visited);
   }
   void dfs_se_components(T src){
    unordered_map<T, bool> visited;
    DFS_helper(src,visited);
    int count=1;
    for(auto p: adj){
        if(!visited[p.first]){
            DFS_helper(p.first,visited);
            count++;
        }
    }
    cout<<"\n Components : "<<count<<endl;
   }
   
};
int main() {
   Graph<int> g;
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(2,4);
    g.AddEdge(3,4);
    g.AddEdge(3,5);
    g.AddEdge(6,7);
    g.AddEdge(16,17);


    // either ab make src and map and pass it then
    int src= 0;
    // unordered_map<int, bool > visited;
    // g.DFS(src,visited);
    // ya use that helper ke trhough wala dfs and no need to pass it alag se
    g.dfs(src);
    g.dfs_se_components(src);
    return 0;
}