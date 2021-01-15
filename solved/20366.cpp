#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n; scanf("%d", &n);
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &seq[i]);

	sort(seq.begin(), seq.end());

	ll ans = 2e9 + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int l = 0, r = n - 1;
			ll s1 = seq[i] + seq[j];
			while (l < r) {
				if (l == i || l == j) {
					++l; continue;
				}
				else if (r == i || r == j) {
					--r; continue;
				}
				
				ll s2 = seq[l] + seq[r];
				ans = min(ans, abs(s1 - s2));

				if (s2 < s1) ++l;
				else if (s2 > s1) --r;
				else break;

			}
		}
	}
	printf("%lld", ans);
}
