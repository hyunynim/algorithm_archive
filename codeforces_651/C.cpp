#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n,k; scanf("%d %d", &n, &k);
		vector<ll> s1(n);
		vector<int> s2(k);
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			scanf("%lld", &s1[i]);
		for (int i = 0; i < k; ++i)
			scanf("%d", &s2[i]);
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		for (int i = 0; i < k; ++i) {
			if (s2[i] == 1) {
				ans += s1.back() * 2;
				s1.pop_back();
			}
			else {
				reverse(s2.begin(), s2.end());
				while (s2.size() && s2.back() == 1)
					s2.pop_back();
				break;
			}
		}
		if (s1.size()) {
			int l = 0;
			for (int i = 0; i < s2.size(); ++i) {
				ans += s1.back() + s1[l];
				s1.pop_back();
				l += s2[i] - 1;
			}
		}
		printf("%lld\n", ans);
	}
}