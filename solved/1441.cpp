#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
int main() {
	int n, l, r; scanf("%d %d %d", &n, &l, &r);
	vector<ll> seq(n);
	bool hasOne = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		if (seq[i] == 1)
			hasOne = 1;
	}
	if (hasOne) {
		printf("%d", r - l + 1); return 0;
	}

	int noUse = 0;
	for (int i = 0; i < n; ++i) 
		for (int j = i + 1; j < n; ++j) 
			if (seq[j] % seq[i] == 0)
				noUse |= (1 << j);
	noUse = ~noUse;
	ll ans = 0;
	for (int i = (1 << n) - 1; i; --i) {
		int cnt = 0;
		ll res = 1;
		bool ok = 1;
		int s = i & noUse;
		for (int j = 0; j < n; ++j) {
			if (s & (1 << j)) {
				++cnt;
				res = lcm(res, seq[j]);
				if (res > r) {
					ok = 0;
					break;
				}
			}
		}
		if (ok) {
			ans += r / res * (cnt % 2 ? 1 : -1);
			ans -= (l - 1) / res * (cnt % 2 ? 1 : -1);
		}
	}
	printf("%lld", ans);
}