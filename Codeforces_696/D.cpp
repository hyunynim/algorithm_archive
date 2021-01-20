#include<bits/stdc++.h>
using namespace std;
int n;
int d[2][202020];
vector<int> seq;
int go(int l, int r, int toPick, int remain) {
	if (r == n) {
		return remain == 0;
	}
	int& res = d[toPick][l];
	if (~res) return res;
	res = 0;
	res = go(s + 1, toPick, seq[s] - r);
	if (toPick)
		res = max(res, go(s + 1, 0, r - seq[s]));
	return res;
}
int main() {
	int t; scanf("%d", &t);
	for (int i = 0; i < 202020; ++i) {

	}
	while (t--) {
		scanf("%d", &n);
		seq.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		memset(d, -1, sizeof(d));
		if (go(1, 1, seq[0]))
			puts("YES");
		else
			puts("NO");
		seq.clear();
	}
}