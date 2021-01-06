#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("1.txt", "r", stdin);
	//for (int i = 0; i < 4096; ++i)
	//	printf("%d ", 536870912);
	//return 0;
	int t; scanf("%d", &t);
	while (t--) {
		int n, x; scanf("%d %d", &n, &x);
		vector<ll> seq(n), s2(n);
		ll ans = 0;
		int m = 1e9, idx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &seq[i]);
			ans += seq[i];
			int cnt = 0;
			ll tmp = seq[i];
			while (tmp % x == 0) {
				++cnt;
				tmp /= x;
			}
			s2[i] = cnt;
			if (m > cnt) {
				m = cnt;
				idx = i;
			}
		}		
		for (int i = 0; i < idx; ++i) 
			ans += (m + 1) * seq[i];
		for(int i = idx; i<n; ++i)
			ans += m * seq[i];
		printf("%lld\n", ans);
	}
}