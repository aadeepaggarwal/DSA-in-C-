#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <list>
#include <queue>
using namespace std;


class Graph {
public:
	map < string, list<string > >adj;

	void addEdge(string u, string v, bool bidir = false) {
		adj[u].push_back(v);
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << "-->";
			for (auto n : p.second) {
				cout << n << " ";
			}
			cout << endl;
		}
	}

	void topologicalSortHelper(string src, list<string> &ans,
	                           unordered_map<string, bool> &visited) {

		visited[src] = true;

		for (auto neighbour : adj[src]) {
			if (!visited[neighbour]) {
				topologicalSortHelper(neighbour, ans, visited);
			}
		}

		ans.push_front(src);
	}

	void topologicalSort() {
		unordered_map<string, int> indegree;
		unordered_map<string, bool> visited;
		list<string> ans;

		for (auto p : adj) {
			for (auto neighbour : p.second) {
				if (indegree.count(neighbour) == 0) indegree[neighbour] = 1;
				else indegree[neighbour]++;
			}
		}

		// Find all those who have indegree->0
		// for (auto p : adj) {
		// 	cout << "Indegree: " << p.first << " : " << indegree[p.first] << endl;
		// }
		for (auto p : adj) {
			if (!indegree[p.first]) {
				topologicalSortHelper(p.first, ans, visited);
			}
		}

		for (auto el : ans) {
			cout << el << " ";
		}
		cout << endl;
	}

	void topologicalSort1() {
		unordered_map<string, bool> visited;
		list<string> ans;

		for (auto p : adj) {
			if (!visited[p.first])
				topologicalSortHelper(p.first, ans, visited);
		}

		for (auto el : ans) {
			cout << el << " ";
		}
		cout << endl;
	}
	list<string> topologicalsort_BFS(){
		unordered_map<string, int> indegree;
		unordered_map<string, bool> visited;
		list<string>ans;

		for(auto p: adj ){
			for(auto child: p.second){
				indegree.count(child)? indegree[child]++ :indegree[child]=1;// agar indegree exists to ++ kardo warna kyonki 1st time mila to 1 kardo because second column mein mila
			}
		}

		queue<string> q;
		for(auto p: adj){
			if(indegree.count(p.first)==0){
				q.push(p.first);// matlab ki agar 0 hai indegree to push kardo queue mein
			}
		}

		while(!q.empty()){
			auto f= q.front();// write auto kyonki ya to jo pair hai string and list of string ka poor poora likho
			q.pop();
			ans.push_back(f);// jo queue mein 0 indegree wala 
			for(auto child: adj[f]){
				if(indegree[child]){// agar child ki indegree exists then -- it
					indegree[child]--;
					if(indegree[child]==0){// agar ye -- karke 0 ho gayi to push that in queue too
						q.push(child);
					}
				}
			}
		}

		return ans;

	}
};

int main() {

	Graph g;
	g.addEdge("English", "Maths");
	g.addEdge("Hindi", "Maths");
	g.addEdge("Maths", "HTML");
	g.addEdge("HTML", "CSS");
	g.addEdge("CSS", "Bootstrap");
	g.addEdge("CSS", "JS");
	g.addEdge("Maths", "C++");
	g.addEdge("C++", "MERN");
	g.addEdge("C++", "CP");
	list<string> ans =g.topologicalsort_BFS();
	for(auto x: ans){
		cout<<x<<" ";
	}
	cout<<endl;
	// g.topologicalsort_BFS();

	return 0;
}