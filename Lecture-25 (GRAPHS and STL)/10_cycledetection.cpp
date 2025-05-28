
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, list<T> > adj;

	void addEdge(T u, T v, bool bidir = false) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << "--> ";
			for (auto neigh : p.second) {
				cout << neigh << ", ";
			}
			cout << endl;
		}
	}

	bool isCyclicHelper(T src, unordered_map<T, bool> &inPath ,
	                    unordered_map<T, bool> &visited) {
		visited[src] = true;
		inPath[src] = true;

		for (auto child : adj[src]) {
			if (!visited[child]) {
				bool kyaCycleHai = isCyclicHelper(child, inPath, visited);
				if (kyaCycleHai == true) {
					return true;
				}
			}
			else if (visited[child] and inPath[child]) {
				return true;
			}
		}

		inPath[src] = false;
		return false;
	}


	bool isCyclic() {
		unordered_map<T, bool> visited;
		unordered_map<T, bool> inPath;

		for (auto p : adj) {
			if (!visited[p.first]) {
				bool ans = isCyclicHelper(p.first, inPath, visited);
				if (ans) return true;
			}
		}

		return false;
	}
};

int main() {

	Graph<int> g;


	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 4);
	g.addEdge(4, 0);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(3, 5);

	if (g.isCyclic()) {
		cout << "Cycle hai\n";
	}
	else {
		cout << "Cycle nahi hai\n";
	}


	return 0;
}
