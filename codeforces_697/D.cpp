#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> s2;
vector<ll> s1;
ll n, m;
ll d[2][202020];
vector<pair<ll, int>> seq;
ll go(int s, int inc, ll cur) {
	if (s >= n) return cur >= m ? 0 : 1e9;

	auto& res = d[inc][s];
	if (~res) return res;
	res = 1e9;
	ll next = inc ? seq[s].first : 0;
	res = min(res, go(s + 1, 1, cur + next));
	res = min(res, go(s + 1, 0, cur + next));
	res += inc;
	return res;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(d, -1, sizeof(d));
		scanf("%lld %lld", &n, &m);
		priority_queue<pair<ll, int>> q;
		ll sum = 0;
		seq.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &seq[i].first);
			sum += seq[i].first;
		}
		for (int i = 0; i < n; ++i)
			scanf("%lld", &seq[i].second);
		
		if (sum < m)
			puts("-1");
		else {
			printf("%lld\n", min(go(0, 1, 0), go(0, 0, 0)));
		}
	}
}