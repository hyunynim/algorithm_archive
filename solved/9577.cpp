#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1010;
struct edg { int pos, cap, rev; };
vector<edg> gph[MAXN];
bool chk[111][222];
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
	const int source = 999, sink = 1000;
	int t; scanf("%d", &t);
	while(t--){
		clear();
		memset(chk, 0, sizeof(chk));
		int n, m; scanf("%d %d", &n, &m);
		add_edge(source, 0, 1);
		for(int i = 1; i<=100; ++i){
			add_edge(source, i, 1);
			add_edge(i + 100, sink, 1);
		}
		for(int mm = 0; mm<m; ++mm){
			int t1, t2, a; scanf("%d %d %d", &t1, &t2, &a);
			for(int i = 0; i<a; ++i){
				int num; scanf("%d", &num);
				for(int j = t1; j<t2; ++j){
					if(chk[j][num + 100]) continue;
					add_edge(j, num + 100, 1);
					chk[j][num + 100] = 1;
				}
			}
		}
		auto res = match(source, sink);
		if(res != n)
			puts("-1");
		else{
			int mx = 0;
			for(int i = 0; i<=100; ++i){
				for(auto cur : gph[i]){
					if(101 <= cur.pos && cur.pos <= 200 && cur.cap == 0){
						mx = max(mx, i);
						break;
					}
				}
			}
			
			printf("%d\n", mx + 1);
		}
	}
}
