#include <iostream>
#include<unordered_map>
#include<list>

using namespace std;
// for Graph <d_type, d_type> format we can use template
// template<typename T, typename U> 
// if U and V are same so we can use only one T/U everywhere 
template<typename T> 
class Graph{
    public:
    unordered_map<T,list<T>> adj;
    void AddEdge(T u, T v, bool Bidirectional= true){
        adj[u].push_back(v);
        if(Bidirectional){
            adj[v].push_back(u);
        }
    }
   void print(){
        for(auto p: adj){// go to each cell of main map (array of array hai na)
            cout<<p.first<<"-->";
            for(auto neighbour : p.second){// p.second is the list of elemnts at that node
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    Graph<string> g;
    g.AddEdge("Putin","Trump",false);
    g.AddEdge("Putin","Modi",false);
    g.AddEdge("Putin","Pope",false);
    g.AddEdge("Trump","Modi");
    g.AddEdge("Modi","Yogi");
    g.AddEdge("Prabhu","Modi",false);

    g.print();
    return 0;
}