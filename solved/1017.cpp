#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2020;
struct edg { int pos, cap, rev; };
vector<vector<edg>> gph(MAXN);
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

bool sieve[1010101];
void pre(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i * i <= 1010101; ++i){
		if(sieve[i]) continue;
		for(int j = i * i; j<1010101; j += i)
			sieve[j] = 1;
		}
	}
int main() {
	pre();
	const int source = 0, sink = 2000;
	int n; scanf("%d", &n);
	vector<int> seq(n), odd, even;
	for(int i = 0; i<n; ++i){
		scanf("%d", &seq[i]);
	}
	vector<int> ans;
	for(int i = 1; i<n; ++i){
		if(sieve[seq[0] + seq[i]]) continue;
		odd.clear(); even.clear();
		clear();
		for(int j = 1; j<n; ++j){
			if(j == i) continue;
			if(seq[j] % 2) odd.push_back(seq[j]);
			else even.push_back(seq[j]);
		}

		for(int j = 0; j<odd.size(); ++j){
			add_edge(source, odd[j], 1);
			for(int k = 0; k<even.size(); ++k){
				if(!sieve[odd[j] + even[k]]) add_edge(odd[j], even[k], 1);
				if(j == 0) add_edge(even[k], sink, 1);
			}
		}
		int res = match(source, sink);
		if(res == n/2 - 1) ans.push_back(seq[i]);
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans)
		printf("%d ", i);
	if(ans.empty()) printf("-1");
}
