#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[202020];
int n;
vector<ll> seq;
ll go(int s) {
	if (s >= n)
		return 0;
	ll& res = d[s];
	if (~res) return res;
	res = seq[s] + go(s + seq[s]);
	return res;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(d, -1, sizeof(d));
		seq.clear();
		scanf("%d", &n);
		seq.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &seq[i]);
		ll ans = 0;
		for (int i = 0; i < n; ++i) 
			ans = max(ans, go(i));
		printf("%lld\n", ans);
	}
}