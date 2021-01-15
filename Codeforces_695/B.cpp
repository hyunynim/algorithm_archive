#include<bits/stdc++.h>
using namespace std;

int d[2][303030]; int n;
vector<int> seq;
int chk(int s) {
	if (s > 0 && s < n - 1)
		return (seq[s - 1] < seq[s] && seq[s] > seq[s + 1]) || (seq[s - 1] > seq[s] && seq[s] < seq[s + 1]);
	else
		return 0;
}
int go(int s, int toPick) {
	if (s >= n) return 0;
	int& res = d[toPick][s];
	if (~res) return res;
	res = 1e9;
	if (toPick) {
		res = min(res, go(s + 2, 0) - (chk(s - 1)));
	}
	res = min(res, go(s + 1, toPick) + chk(s));
	return res;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(d, -1, sizeof(d));
		scanf("%d", &n);
		seq.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &seq[i]);
		go(0, 1);
		go(0, 0);
		printf("%d\n", min(d[0][0], d[1][0]));
	}
}