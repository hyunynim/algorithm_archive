#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8;
typedef long long ll;
struct EDGE {
	ll from, to, w;
};
vector<EDGE> edge;
vector<ll> BellmanFord(int v, int st) {
	vector<ll> ans(v + 1);
	fill(ans.begin(), ans.end(), inf);
	ans[st] = 0;
	for (int i = 1; i <= v; ++i) {
		for (int j = 0; j < edge.size(); ++j) {
			int from = edge[j].from, to = edge[j].to, w = edge[j].w;
			if (ans[to] > ans[from] + w) {
				if (i == v) {
					ans[0] = -1; return ans;
				}
				ans[to] = ans[from] + w;
			}
		}
	}
	return ans;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int v, e, w;
		scanf("%d %d %d", &v, &e, &w);
		edge.resize(e + w);
		for (int i = 0; i < e + w; ++i) {
			scanf("%lld %lld %lld", &edge[i].from, &edge[i].to, &edge[i].w);
			if (i >= e)
				edge[i].w *= -1;
		}
		for (int i = 0; i < e; ++i)
			edge.push_back({ edge[i].to, edge[i].from, edge[i].w });
		vector<ll> ans = BellmanFord(v, 1);
		if (ans[0] == -1)
			puts("YES");
		else
			puts("NO");
		edge.clear();
	}
}