#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, x; scanf("%d %d", &n, &x);
		vector<ll> seq(n);
		ll ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &seq[i]);
			ans2 += seq[i] / x + (seq[i] % x != 0);
			ans1 += seq[i];
		}
		ans1 = ans1 / x + (ans1 % x != 0);
		printf("%lld %lld\n", ans1, ans2);
	}
}