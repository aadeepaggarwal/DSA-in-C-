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
    map<T,list<T>> adj;// make ordered map iss bar taki sorted order mein aa jaye
    void AddEdge(T u, T v, bool Bidirectional=true){
        adj[u].push_back(v);
        if(Bidirectional){
            adj[v].push_back(u);
        }
    }

    void BFS(T src){
        queue<T> q;
        unordered_map<T,bool> visited;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T x=q.front();
            q.pop();
            cout<<x<<" ";
            for(auto child: adj[x]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
        cout<<endl;
    }
    void SSSP(T src){
        queue<T> q;
        unordered_map<T,bool> visited;
        unordered_map<T,int> distance;// make distance ka bhi ek map and ismein we store key(the node) and value as distance from source of that key
        q.push(src);
        visited[src]=true;
        distance[src]=0;
        while(!q.empty()){
            T x=q.front();
            q.pop();

            for(auto child: adj[x]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    distance[child]=distance[x]+1;
                }
            }
        }
        for(auto p: distance){
            cout<<"Distance of "<<p.first/*means key utha */<<" from "<<src<<" : "<<p.second/* second wala stores the distance */<<endl;
        }
    }
    void path(T src, T destination){
        queue<T> q;
        unordered_map<T,bool> visited;
        unordered_map<T,int> distance;// make distance ka bhi ek map and ismein 
        //we store key(the node) and value as distance from source of that key
        unordered_map<T,int> parent;// store parent of each node to get path of one node(destination) from source
        q.push(src);
        visited[src]=true;
        distance[src]=0;
        parent[src]=src;// key= child value= parent 
        while(!q.empty()){
            T x=q.front();
            q.pop();

            for(auto child: adj[x]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    parent[child]=x;
                    distance[child]=distance[x]+1;
                }
            }
        }
        while(destination!= parent[destination]/*means jab tak ham source pe nahi pahuch jaate*/){
            cout<<destination<<"<--";
            destination=parent[destination];// update current wali destination
        }
        cout<<destination<<endl;
    }
   void print(){
        for(auto p: adj){
            cout<<p.first<<"-->";
            for(auto neighbour : p.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
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
cout<<"Print the graph\n";
    g.print();
cout<<"Print BFS order\n";
    g.BFS(0);
cout<<"Print Shortest path from source of each vertex\n";
    g.SSSP(0);
cout<<"Print the path from source of each vertex\n";
    g.path(0,5);
    return 0;
}