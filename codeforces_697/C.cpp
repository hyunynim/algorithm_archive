#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	vector<ll> nodeNum;
	Segment(int n) {
		++n;
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
		nodeNum.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
			nodeNum[s] = node;
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b, k; scanf("%d %d %d", &a, &b, &k);
		vector<pair<int, int>> seq(k);
		for (int i = 0; i < k; ++i)
			scanf("%d", &seq[i].first);
		int bm = 0;
		for (int i = 0; i < k; ++i) {
			scanf("%d", &seq[i].second);
			bm = max(bm, seq[i].second);
		}
		sort(seq.begin(), seq.end());
		int cur = seq[0].first;
		ll res = 0;
		Segment sg(bm);
		sg.init(1, 1, bm);
		vector<pair<int, int>> tmp;
		for (int i = 0; i < k; ++i) {
			if (cur == seq[i].first) {
				auto sum = sg.tree[1];
				auto neg = sg.tree[sg.nodeNum[seq[i].second]];
				res += sum - neg;
				tmp.push_back(seq[i]);
			}
			else {
				cur = seq[i].first;
				for (auto j : tmp)
					sg.update(1, 1, bm, j.second, 1);
				tmp.clear();
				tmp.push_back(seq[i]);
				auto sum = sg.tree[1];
				auto neg = sg.tree[sg.nodeNum[seq[i].second]];
				res += sum - neg;
			}
		}
		printf("%lld\n", res);
	}
}