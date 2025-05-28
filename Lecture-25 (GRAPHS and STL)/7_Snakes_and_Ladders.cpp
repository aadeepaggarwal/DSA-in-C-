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
   int Board[50]={0};
   Board[2]=13;
   Board[5]=2;
   Board[9]=18;
   Board[18]=11;
   Board[17]=-13;
   Board[20]=-14;
   Board[24]=-8;
   Board[25]=-10;
   Board[32]=-2;
   Board[34]=-22;

for(int u=0;u<=36;u++){// har index pe jaak dekhenge ki agar dice pe kuchh bhi agay to kya kya possibilities hain
    for(int dice=1;dice<=6;dice++){// ye dice roll hone ki possibilties
        int v=u+dice;// add dice value
        v+=Board[v];// add board ki situation
        g.AddEdge(u,v,false);// make an edge in graph for each permutation
    }
}
// we can now print shortest path from any number on board to the end 

    return 0;
}