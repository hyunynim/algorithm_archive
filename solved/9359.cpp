#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seq;
bool prime[1010101] = { 1, 1 };
vector<ll> p;
void pre() {
	for (ll i = 2; i < 1010101; ++i) {
		if (prime[i]) continue;
		for (ll j = i * i; j < 1010101; j += i)
			prime[j] = 1;
	}
	for (int i = 2; i<1010101; ++i)
		if (!prime[i])
			p.push_back(i);
}
vector<ll> Fact(ll num) {
	vector<ll> res;
	for (int i = 0; i < p.size(); ++i)
		if (num % p[i] == 0)
			res.push_back(p[i]);
	if (res.empty())
		res.push_back(num);
	return res;
}
int main() {
	pre();
	int t; scanf("%d", &t);
	int cnt = 1;
	while (t--) {
		ll a, b, n; scanf("%lld %lld %lld", &a, &b, &n);
		if (n == 1) {
			printf("Case #%d: %lld\n", cnt++, b - a + 1);
			continue;
		}
		seq = Fact(n);
		ll ans = 0;
		for (int i = (1 << seq.size()) - 1; i; --i) {
			ll res = 1;
			ll flag = -1;
			for (int j = 0; j < seq.size(); ++j) {
				if (i & (1 << j)) {
					res *= seq[j];
					flag *= -1;
				}
			}
			ans += b / res * flag;
			ans -= (a - 1) / res * flag;
		}
		printf("Case #%d: %lld\n", cnt++, b - a + 1 - ans);
		seq.clear();
	}
}
