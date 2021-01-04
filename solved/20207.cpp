#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> cnt(366);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int s, e; scanf("%d %d", &s, &e);
		for (int j = s; j <= e; ++j)
			++cnt[j];
	}

	int m = 0;
	int c = 0;
	int ans = 0;
	for (int i = 1; i <= 365; ++i) {
		if (cnt[i] == 0) {
			ans += c * m;
			m = 0;
			c = 0;
			continue;
		}
		++c;
		m = max(m, cnt[i]);
	}
	ans += c * m;
	printf("%d", ans);
}