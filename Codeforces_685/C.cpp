#include<bits/stdc++.h>
using namespace std;
char msg[1010101];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		vector<int> cnt1(222), cnt2(222);
		scanf("%s", msg);
		for (int i = 0; i < n; ++i)
			++cnt1[msg[i]];

		scanf("%s", msg);
		for (int i = 0; i < n; ++i)
			++cnt2[msg[i]];
		
		int c = 0;
		bool ans = 1;
		for (int i = 'a'; i <= 'z'; ++i) {
			int res = cnt1[i] - cnt2[i] + c;
			if (res < 0) {
				ans = 0;
				break;
			}
			c = res;
			if (c % k) {
				ans = 0;
				break;
			}
		}
		if (ans)
			puts("Yes");
		else
			puts("No");
	}
}