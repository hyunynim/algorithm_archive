#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		bool ans = 0;
		for (int i = 0; i * 2020 <= n; ++i) {
			if ((n - (2020 * i)) % 2021 == 0) {
				puts("YES");
				ans = 1;
				break;
			}
			}
		if(!ans)
			puts("NO");
	}
}