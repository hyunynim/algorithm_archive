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
<<<<<<< HEAD
	for (int i = 2; i < 1010101; ++i)
=======
	for (int i = 2; i<1010101; ++i)
>>>>>>> e3d0509cabc75d7e31993c200aa7ec165897e7d1
		if (!prime[i])
			p.push_back(i);
}
vector<ll> Fact(ll num) {
	vector<ll> res;
<<<<<<< HEAD
	for (int i = 0; i < p.size(); ++i) {
		while (num % p[i] == 0) {
			if(res.empty() || res.back() != p[i])
				res.push_back(p[i]);
			num /= p[i];
		}
	}
	if (res.empty() || num != 1)
=======
	for (int i = 0; i < p.size(); ++i)
		if (num % p[i] == 0)
			res.push_back(p[i]);
	if (res.empty())
>>>>>>> e3d0509cabc75d7e31993c200aa7ec165897e7d1
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
<<<<<<< HEAD
}
=======
}
>>>>>>> e3d0509cabc75d7e31993c200aa7ec165897e7d1
