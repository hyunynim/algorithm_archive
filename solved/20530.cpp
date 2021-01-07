#include<bits/stdc++.h>
using namespace std;
vector<int> adj[202020];
int chk[202020];
bool visited[202020];
vector<int> cycle;
int v1;
void FindCycle(int s, int prev) {
	if (visited[s]) {
		v1 = s;
		cycle.push_back(s);
		return;
	}
	visited[s] = 1;
	for (int i = 0; i < adj[s].size(); ++i) {
		int nx = adj[s][i];
		if (nx == prev) continue;
		
		FindCycle(nx, s);
		
		if (v1 == -1) return;
		
		if (v1 == s) {
			v1 = -1;
			return;
		}
		
		if (v1 > 0) {
			cycle.push_back(s);
			return;
		}

	}
}
void MakeSubtree(int s, int num) {
	if (chk[s]) return;
	chk[s] = num;
	for (int i = 0; i < adj[s].size(); ++i)
		MakeSubtree(adj[s][i], num);
}
int main() {
	int n, q; scanf("%d %d", &n, &q);

	for (int i = 0; i < n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	FindCycle(1, -1);
	
	for (auto i : cycle)
		chk[i] = i;
	for (auto i : cycle) {
		chk[i] = 0;
		MakeSubtree(i, i);
	}
	

	for (int i = 0; i < q; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		if (chk[u] != chk[v])
			puts("2");
		else
			puts("1");
	}
}
