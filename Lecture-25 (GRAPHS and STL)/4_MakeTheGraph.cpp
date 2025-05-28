#include <iostream>
#include <list>
using namespace std;
class Graph{
    public:
    list<int> *adj;// make pointer of list ismein se array of list banake utni list add karenge jitna user input dega
    int n;
    Graph(int n){
        adj=new list<int>[n];// make list at that cell of adj pointer (making array of lists kyonki)
        this->n=n;
    }
    void addEdge(int u, int v, bool bi_directional= true){
        adj[u].push_back(v);// yani ki uth index pe v ko push karde 
        // agar bi directional hai to v and u too connected
        if(bi_directional){
             adj[v].push_back(u);
        }
    }

    void print() {
		for (int i = 0 ; i < n ; i++) {
			cout << i << "-->";
			for (auto neigh : adj[i]) {
				cout << neigh << ", ";
			}
			cout << endl;
		}
	}
};
int main() {
    Graph g(5);

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 3);
	g.addEdge(3, 2);

	g.print();

    return 0;
}