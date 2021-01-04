#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segment {
	vector<int> tree;
	vector<int> seq;
	vector<int> idx;
	Segment(int n) {
		++n;
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		idx.resize(t);
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
			idx[node] = s;
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
			if (tree[node * 2] > tree[node * 2 + 1])
				idx[node] = idx[node * 2 + 1];
			else
				idx[node] = idx[node * 2];
		}
	}

	pair<int, int> query(int node, int s, int e, int i, int j, int & res) {
		if (e < i || s > j) return { -1, 0 };
		if (i <= s && e <= j)
			return { tree[node], idx[node] };
		auto res1 = query(node * 2, s, (s + e) / 2, i, j, res);
		auto res2 = query(node * 2 + 1, (s + e) / 2 + 1, e, i, j, res);
		if (res1.first == -1)
			return res2;
		else if (res2.first == -1) return res1;
		else 
			return min(res1, res2);
		
	}
};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<pair<pair<int,int>, int>> seq1, seq2;
		vector<pair<int, int>> seq;
		for (int i = 0; i < n; ++i) {
			int h, w; scanf("%d %d", &h, &w);
			seq.push_back({ h, w });
			seq1.push_back({ { h, w }, i + 1 });
			seq2.push_back({ { w, h }, i + 1});
		}
		sort(seq1.begin(), seq1.end());
		sort(seq2.begin(), seq2.end());
		vector<int> height, width;
		Segment s1(n + 1), s2(n + 1);
		for (int i = 1; i <= n; ++i) {
			s1.seq[i] = seq1[i - 1].first.second;
			height.push_back(seq1[i - 1].first.first);
		}
		for (int i = 1; i <= n; ++i) {
			s2.seq[i] = seq2[i - 1].first.second;
			width.push_back(seq2[i - 1].first.first);
		}
		s1.init(1, 1, n);
		s2.init(1, 1, n);
		for (int i = 0; i < n; ++i) {
			int idx1 = lower_bound(height.begin(), height.end(), seq[i].first) - height.begin();
			int idx2 = lower_bound(width.begin(), width.end(), seq[i].second) - width.begin();
			int idx3 = lower_bound(height.begin(), height.end(), seq[i].second) - height.begin();
			int idx4 = lower_bound(width.begin(), width.end(), seq[i].first) - width.begin();
			if (idx1 == 0 && idx2 == 0)
				printf("-1 ");
			else {
				int ans = -1;
				if (idx1) {
					auto q = s1.query(1, 1, n, 1, idx1, ans);
					if (q.first >= seq[i].second)
						ans = -1;
					else {
						ans = q.second;
						printf("%d ", seq1[ans - 1].second);
						continue;
					}
				}
				if (idx2) {
					auto q = s2.query(1, 1, n, 1, idx2, ans);
					if (q.first >= seq[i].first)
						ans = -1;
					else {
						ans = q.second;
						printf("%d ", seq2[ans - 1].second);
						continue;
					}
				}
				if (idx3) {
					auto q = s1.query(1, 1, n, 1, idx3, ans);
					if (q.first >= seq[i].first)
						ans = -1;
					else {
						ans = q.second;
						printf("%d ", seq1[ans - 1].second);
						continue;
					}
				}
				if (idx4) {
					auto q = s2.query(1, 1, n, 1, idx4, ans);
					if (q.first >= seq[i].second)
						ans = -1;
					else {
						ans = q.second;
						printf("%d ", seq2[ans - 1].second);
						continue;
					}
				}
				printf("-1 ");
			}
		}
		puts("");
	}
}