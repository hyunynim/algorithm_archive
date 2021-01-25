#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2020;
struct edg { int pos, cap, rev; };
vector<edg> gph[MAXN];
void clear() { for (int i = 0; i < MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, int x) {
	gph[s].push_back({ e, x, (int)gph[e].size() });
	gph[e].push_back({ s, 0, (int)gph[s].size() - 1 });
}
int dis[MAXN], pnt[MAXN];
bool bfs(int src, int sink) {
	memset(dis, 0, sizeof(dis));
	memset(pnt, 0, sizeof(pnt));
	queue<int> que;
	que.push(src);
	dis[src] = 1;
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (auto &e : gph[x]) {
			if (e.cap > 0 && !dis[e.pos]) {
				dis[e.pos] = dis[x] + 1;
				que.push(e.pos);
			}
		}
	}
	return dis[sink] > 0;
}
int dfs(int x, int sink, int f) {
	if (x == sink) return f;
	for (; pnt[x] < gph[x].size(); pnt[x]++) {
		edg e = gph[x][pnt[x]];
		if (e.cap > 0 && dis[e.pos] == dis[x] + 1) {
			int w = dfs(e.pos, sink, min(f, e.cap));
			if (w) {
				gph[x][pnt[x]].cap -= w;
				gph[e.pos][e.rev].cap += w;
				return w;
			}
		}
	}
	return 0;
}
ll match(int src, int sink) {
	ll ret = 0;
	while (bfs(src, sink)) {
		int r;
		while ((r = dfs(src, sink, 2e9))) ret += r;
	}
	return ret;
}

int main() {
	const int source = 0, sink = 1000;
	int n, k, d; scanf("%d %d %d", &n, &k, &d);
	for(int i = 1; i<=d; ++i){
		int num; scanf("%d", &num);
		add_edge(500 + i, sink, num);
	}

	for(int i = 1; i<=n; ++i)
		add_edge(source, i, k);
	
	for(int i = 0; i<n; ++i){
		int num; scanf("%d", &num);
		for(int j = 0; j<num; ++j){
			int f; scanf("%d", &f);
			add_edge(i + 1, 500 + f, 1);
		}
	}
	printf("%lld", match(source, sink));
}
