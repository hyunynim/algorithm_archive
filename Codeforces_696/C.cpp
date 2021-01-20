#include<bits/stdc++.h>
using namespace std;
struct EDGE {
	int x, y;
};
vector<EDGE> adj[2020202];
int n;
vector<int> seq;
stack<pair<int, int>> answer;
bool go(int cur, bitset<2020> & pick, int cnt) {
	if (cnt == n) {
		return 1;
	}
	for (auto nx : adj[cur]) {
		bitset<2020> tmp;
		if (pick[nx.x] == 0 && pick[nx.y] == 0) {
			pick[nx.x] = pick[nx.y] = 1;
			if (go(max(seq[nx.x], seq[nx.y]), pick, cnt + 2)) {
				answer.push({ nx.x, nx.y });
				return 1;
			}
			pick[nx.x] = pick[nx.y] = 0;
		}
	}
	return 0;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		seq.clear();
		scanf("%d", &n);
		n <<= 1;
		seq.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		sort(seq.begin(), seq.end());
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				adj[seq[i] + seq[j]].push_back({ i, j });
		bitset<2020> tmp;
		tmp[n - 1] = 1;
		int ans = -1;
		for (int i = n - 2; i >= 0; --i) {
			tmp[i] = 1;
			if (go(seq.back(), tmp, 2)) {
				ans = i;
				answer.push({ i, n - 1 });
				break;
			}
			tmp[i] = 0;
		}
		if (~ans) {
			puts("YES");
			printf("%d\n", seq[answer.top().first] + seq[answer.top().second]);
			while (answer.size()) {
				printf("%d %d\n", seq[answer.top().first], seq[answer.top().second]);
				answer.pop();
			}
		}
		else
			puts("NO");
	}
}