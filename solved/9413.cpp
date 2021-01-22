#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
struct mincostflow {
	struct edg { int pos, cap, rev, cost; };
	vector<edg> gph[MAXN];
	void clear() {
		for (int i = 0; i < MAXN; i++) gph[i].clear();
	}
	void add_edge(int s, int e, int x, int c) {	//x: cap, c: cost
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
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		struct mincostflow mcmf;
		const int s = 0, s1 = 900, s2 = 901, t = 902, t1 = 903, t2 = 904;
		int n, m; scanf("%d %d", &n, &m);
		mcmf.add_edge(s, s1, 1, 0);
		mcmf.add_edge(s, s2, 1, 0);
		mcmf.add_edge(t1, t, 1, 0);
		mcmf.add_edge(t2, t, 1, 0);

		for (int i = 1; i <= n; ++i) {
			mcmf.add_edge(s1, i, 1, 0);
			mcmf.add_edge(s2, i, 1, 0);
			mcmf.add_edge(i + n, t1, 1, 0);
			mcmf.add_edge(i + n, t2, 1, 0);

			mcmf.add_edge(i, i + n, 1, -1);
		}

		for (int i = 0; i < m; ++i) {
			int a, b; scanf("%d %d", &a, &b);
			mcmf.add_edge(a + n, b, 1, 0);
		}
		printf("%d\n", -mcmf.match(s, t));
		mcmf.clear();
	}
}
