#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct LazySeg {
	vector<ll> seq;
	vector<ll> tree;
	vector<ll> lazy;
	LazySeg(int n) {
		seq.resize(n);
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1)) - 1;
		tree.resize(tree_size);
		lazy.resize(tree_size);
	}
	ll init(int node, int start, int end) {
		if (start == end) {
			return tree[node] = seq[start];
		}
		else {
			return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
		}
	}
	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void update_range(int node, int start, int end, int left, int right, ll diff) {
		update_lazy(node, start, end);
		if (left > end || right < start) {
			return;
		}
		if (left <= start && end <= right) {
			tree[node] += (end - start + 1) * diff;
			if (start != end) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		update_range(node * 2, start, (start + end) / 2, left, right, diff);
		update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll sum(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
};
string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int h, m, s;
	sscanf(play_time.c_str(), "%d:%d:%d", &h, &m, &s);
	int n = s + m * 60 + h * 3600;
	LazySeg seg(n + 1);
	sscanf(adv_time.c_str(), "%d:%d:%d", &h, &m, &s);
	int len = s + m * 60 + h * 3600;
	for (int i = 0; i < logs.size(); ++i) {
		int sh, sm, ss, eh, em, es;
		sscanf(logs[i].c_str(), "%d:%d:%d-%d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);
		ss += sm * 60 + sh * 3600;
		es += em * 60 + eh * 3600;
		seg.update_range(1, 0, n, ss, es, 1);
	}
	ll ans = -1, ansI = -1;
	for (int i = 0; i + len <= n; ++i) {
		ll res = seg.sum(1, 0, n, i, i + len);
		if (ans < res) {
			ans = res;
			ansI = i;
		}
	}

	vector<int> t;
	int cur = 3600;
	for (int i = 0; i < 3; ++i) {
		t.push_back(ansI / cur);
		ansI %= cur;
		cur /= 60;
	}
	for (int i = 0; i < 3; ++i) {
		string str = "";
		for(int j = 0; j<2; ++j){
			str.push_back(t[i] % 10 + '0');
			t[i] /= 10;
		}
		reverse(str.begin(), str.end());
		answer += str + ":";
	}
	answer.pop_back();
	return answer;
}
int main() {
	solution("02:03:55", "00:14:15", { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" });
}