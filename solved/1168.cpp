#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		++n;
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query1(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query1(node * 2, s, (s + e) / 2, i, j) + query1(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}
	int query2(int node, int s, int e, int num, int left) {
		if (s == e)
			return s;
		int l = tree[node * 2] - left;
		if (l < num)
			return query2(node * 2 + 1, (s + e) / 2 + 1, e, num - l, 0);
		else
			return query2(node * 2, s, (s + e) / 2, num, left);
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
vector<int> ans1, ans2;
void naive(int n, int k) {
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	while (q.size()) {
		for (int i = k - 1; i > 0; --i) {
			q.push(q.front());
			q.pop();
		}
		ans2.push_back(q.front());
		q.pop();
	}
}
int main() {
	int n, k; scanf("%d %d", &n, &k);
	naive(n, k);
	Segment s(n);
	for (int i = 1; i <= n; ++i) {
		s.seq[i] = 1;
	}
	s.init(1, 1, n);
	printf("<");
	int cur = 1;
	int move = k;
	for(int i = 0; i<n; ++i){
		int l = s.query1(1, 1, n, 1, cur - 1);
		int r = s.query1(1, 1, n, cur, n);
		if (cur == 1){
			if (s.tree[1] < move) {
				move %= s.tree[1];
				if (move == 0) move = s.tree[1];
				--i;
				continue;
			}
		}
		if (r < move) {
			move -= r;
			--i;
			cur = 1;
			continue;
		}
		int ans = s.query2(1, 1, n, max(move, 1), l);
		s.update(1, 1, n, ans, -1);
		printf("%d%s", ans, i == n - 1 ? "" : ", ");
		ans1.push_back(ans);
		cur = ans;
		move = k;
	}
	printf(">");
	if (ans1 != ans2) {
		puts("Mine");
		for (auto i : ans1)
			printf("%d ", i);
		puts("\nAns");
		for (auto i : ans2)
			printf("%d ", i);
	}
}