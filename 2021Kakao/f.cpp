#include<bits/stdc++.h>

using namespace std;
const int MAXN = 606060;
struct mincostflow {
	struct edg { int pos, cap, rev, cost; };
	vector<edg> gph[MAXN];
	void clear() {
		for (int i = 0; i < MAXN; i++) gph[i].clear();
	}
	void add_edge(int s, int e, int x, int c) {
		gph[s].push_back({ e, x, (int)gph[e].size(), c });
		gph[e].push_back({ s, 0, (int)gph[s].size() - 1, -c });
	}
	int dist[MAXN], pa[MAXN], pe[MAXN];
	bool inque[MAXN];
	bool spfa(int src, int sink) {
		memset(dist, 0x3f, sizeof(dist));
		memset(inque, 0, sizeof(inque));
		queue<int> que;
		dist[src] = 0;
		inque[src] = 1;
		que.push(src);
		bool ok = 0;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (x == sink) ok = 1;
			inque[x] = 0;
			for (int i = 0; i < gph[x].size(); i++) {
				edg e = gph[x][i];
				if (e.cap > 0 && dist[e.pos] > dist[x] + e.cost) {
					dist[e.pos] = dist[x] + e.cost;
					pa[e.pos] = x;
					pe[e.pos] = i;
					if (!inque[e.pos]) {
						inque[e.pos] = 1;
						que.push(e.pos);
					}
				}
			}
		}
		return ok;
	}
	int match(int src, int sink) {
		int ret = 0;
		while (spfa(src, sink)) {
			int cap = 1e9;
			for (int pos = sink; pos != src; pos = pa[pos])
				cap = min(cap, gph[pa[pos]][pe[pos]].cap);

			ret += dist[sink] * cap;
			for (int pos = sink; pos != src; pos = pa[pos]) {
				int rev = gph[pa[pos]][pe[pos]].rev;
				gph[pa[pos]][pe[pos]].cap -= cap;
				gph[pos][rev].cap += cap;
			}
		}
		return ret;
	}
}mcmf;
vector<int> gNo[303030];
vector<int> adj[303030];
int solution(vector<int> sales, vector<vector<int>> links) {
	for (int i = 0; i < links.size(); ++i)
		adj[links[i][0]].push_back(links[i][1]);

	queue<int> q;
	q.push(1);
	int g = 0;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (adj[cur].size())
			gNo[cur].push_back(++g);
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			gNo[nx].push_back(g);
			q.push(nx);
		}
	}

	for (int i = 1; i <= sales.size(); ++i) {
		mcmf.add_edge(0, i, sales.size(), sales[i - 1]);
		for (int j = 0; j < gNo[i].size(); ++j) {
			mcmf.add_edge(i, sales.size() + gNo[i][j], 1, 0);
		}
	}
	for (int i = 1; i <= g; ++i)
		mcmf.add_edge(sales.size() + i, sales.size() * 2 + 1, 1, 0);
	int ans = mcmf.match(0, sales.size() * 2 + 1);
	return ans;
}