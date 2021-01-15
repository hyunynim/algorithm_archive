#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[1010][1010];
ll mod = 1e9 + 9;
int main() {
	d[0][0] = 1;
	for (int i = 0; i < 1010; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0)
				d[i][j] = 1;
			else {
				if (i) {
					if (j > 0)
						d[i][j] += d[i - 1][j - 1];
					d[i][j] += d[i - 1][j];
				}
				d[i][j] %= mod;
			}
		}
	}
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	ll ans = d[m + k - 1][k];
	if (k - n > 0) {
		
	}
	ans %= mod;
	printf("%lld", ans);
}