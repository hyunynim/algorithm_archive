#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		vector<int> s1(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &s1[i]);

		vector<int> s2(m);
		for (int i = 0; i < m; ++i) 
			scanf("%d", &s2[i]);
		
		sort(s1.begin(), s1.end());
		reverse(s1.begin(), s1.end());
		ll ans = 0;
		int l = 0, r = s1[0] - 1;
		for (int i = 0; i < s1.size(); ++i) {
			r = min((s1[i] - 1), r);
			max(r, 0);
			l = min(l, m - 1);
			if (s2[l] < s2[r] && l < r)
				ans += s2[l++];
			else if (l >= r)
				ans += s2[max(s1[i] - 1, 0)];
			else
				ans += s2[r--];
		}
		printf("%lld\n", ans);
	}
}