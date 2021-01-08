#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	vector<int> chk(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	sort(seq.begin(), seq.end());

	int ans = 2e9 + 1;
	for (int i = 0; i < n; ++i) {
		chk[i] = 1;
		for (int j = i + 1; j < n; ++j) {
			chk[j] = 1;
			int l = 0, r = n - 1;
			int s1 = seq[i] + seq[j];
			while (l < r) {
				if (chk[l]) ++l;
				else if (chk[r]) --r;
				
				int s2 = seq[l] + seq[r];
				ans = min(ans, abs(s1 - s2));

				if (s2 < s1)
					++l;
				else
					--r;
			}
			chk[j] = 0;
		}
		chk[i] = 0;
	}
	printf("%d", ans);
}
