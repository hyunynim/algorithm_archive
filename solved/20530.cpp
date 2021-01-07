#include<bits/stdc++.h>
using namespace std;
vector<int> adj[202020];
int chk[202020];
bool visited[202020];
vector<int> cycle;
map<int, int> connect;
int v1, v2;
void go(int s, int prev) {
	if (chk[s]) {
		v1 = s;
		cycle.push_back(s);
		return;
	}
	chk[s] = 1;
	for (int i = 0; i < adj[s].size(); ++i) {
		int nx = adj[s][i];
		if (nx == prev) continue;
		
		go(nx, s);
		
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
int go2(int s, int num) {
	if (chk[s]) return 0;
	chk[s] = num;
	for (int i = 0; i < adj[s].size(); ++i)
		go2(adj[s][i], num);
	return 2;
}
int c = -1;
void go3(int s) {
	if (visited[s]) return;
	visited[s] = 1;
	for (auto i : adj[s]) {
		if (chk[s] != 2 && chk[i] == 2)
			connect[chk[s]] = i;
		if (chk[s] == 2 && chk[i] != 2)
			connect[chk[i]] = s;
		go3(i);
	}
}
int main() {
	int n, q; scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	go(1, -1);
	memset(chk, 0, sizeof(chk));
	for (auto i : cycle) {
		chk[i] = 2;
		connect[i] = -1;
	}
	int cnt = -1;
	for (int i = 1; i <= n; ++i) 
		cnt -= go2(i, cnt);

	go3(1);

	for (int i = 0; i < q; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		int cu = chk[u];
		int cv = chk[v];
		if (cu == cv && cu == 2)
			puts("2");
		else if (cu == cv)
			puts("1");
		else {
			if ((cu == 2 && connect[cv] == u) 
				|| (cv == 2 && connect[cu] == v)
				|| (connect[cu] == connect[cv]))
				puts("1");
			else
				puts("2");
		}

	}
}
