#include <iostream>
#include<vector>
using namespace std;

class DSU {
public:
	vector<int> parent, rank;
	DSU(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);

		for (int i = 0; i <= n; ++i) make_set(i), rank[i] = 1;
	}

	void make_set(int i) {
		parent[i] = i;
	}

	int find_set(int u) {
		if (u == parent[u]) return u;

		return parent[u] = find_set(parent[u]);// to do path compression we store parent directly as the main leader
	}

	void union_set(int u, int v) {
		int leader_u = find_set(u);
		int leader_v = find_set(v);

		if (rank[leader_u] < rank[leader_v]) swap(leader_u, leader_v);

		parent[leader_v] = leader_u;
		if (rank[leader_v] == rank[leader_u]) rank[leader_u]++;
	}
};

int main() {


	return 0;
}