#include<bits/stdc++.h>
using namespace std;
int d[55][55];
const int mod = 10007;
int main() {
	for (int i = 0; i < 55; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0)
				d[i][j] = 1;
			else if (i) {
				if(0 < j)
					d[i][j] += d[i - 1][j - 1];
				if (j < i)
					d[i][j] += d[i - 1][j];
			}
			d[i][j] %= mod;
		}
	}
	int n; scanf("%d", &n);
	if (n <= 3)
		printf("0");
	else {
		int ans = 0;
		for (int i = 1; i <= n / 4; ++i) {
			int tmp = (d[13][i] * d[52 - 4 * i][n - 4 * i]) % mod;
			if (i % 2) {
				ans += tmp;
			}
			else {
				ans -= tmp;
				ans += mod;
			}
			ans %= mod;
		}
		printf("%d", ans);
	}
}
