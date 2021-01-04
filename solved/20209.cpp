#include<bits/stdc++.h>
using namespace std;
int chk[1010101];
map<int, int> comp;
int ans[1010101];
int cnt = 1;
int n, k;
void go(int s, int toPick) {
	if (toPick == 0 || comp[s]) return;
	if(comp[s] == 0)
		comp[s] = cnt++;
	int tmp = s;
	int dig = tmp % 10;
	bool ok = 1;
	for(int i = 0; i<n; ++i){
		if (tmp % 10 != dig) {
			ok = 0; break;
		}
		dig = tmp % 10;
		tmp /= 10;
	}
	if (ok)
		ans[comp[s]] = 1;
	for (int i = 0; i < 5; ++i)
		go(s * 10 + i, toPick - 1);
}
int vec2i(vector<int>& seq) {
	int res = 0;
	for (int i = 0; i < seq.size(); ++i)
		res = res * 10 + seq[i];
	return comp[res];
}
int main() {
	scanf("%d %d", &n, &k);
	vector<int> seq(n);
	vector<vector<int>> sw;
	go(0, n + 1);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &seq[i]);
	for (int i = 0; i < k; ++i) {
		int k; scanf("%d", &k);
		sw.push_back(vector<int>(n));
		for (int j = 0; j < k; ++j) {
			int num; scanf("%d", &num);
			sw.back()[num - 1] = i + 1;
		}
	}

	queue<vector<int>> q;

	q.push(seq);
	chk[vec2i(seq)] = 1;

	while (q.size()) {
		auto cur = q.front(); q.pop();
		int ccur = vec2i(cur);
		if (ans[vec2i(cur)]) {
			printf("%d", chk[vec2i(cur)] - 1);
			return 0;
		}
		vector<int> tmp(n);
		for (int i = 0; i < sw.size(); ++i) {
			for (int j = 0; j < n; ++j) 
				tmp[j] = (cur[j] + sw[i][j]) % 5;
			int cc = vec2i(tmp);
			if (chk[cc]) continue;
			chk[cc] = chk[ccur] + 1;
			q.push(tmp);
		}
	}
	printf("-1");
}