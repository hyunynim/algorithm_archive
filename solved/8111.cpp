#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;

struct edge {
	int to, w;
};
vector<edge> adj[101];
int d[101][20202];
int chk[20202];

ll pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res % m;
}
void pre() {
	for (int i = 1; i <= 20000; ++i) {
		for (int j = 0; j <= 100; ++j) {
			d[j][i] = pow(10, j, i);
		}
	}
}
void init() {
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < 101; ++i)
		adj[i].clear();
		
}
bitset<101> go(int s) {
	init();	
	queue<pair<bitset<101>, int>> q;
	bitset<101> tmp;
	q.push({ tmp, 0 });

	while (q.size()) {
		auto cur = q.front(); q.pop();
		auto b = cur.first;
		auto w = cur.second;
		if (b.any() && w == 0) {
			return b;
		}
		for (int i = 0; i < 101; ++i) {
			if (b[i] == 0) {
				tmp[i] = 1;
				auto nx = b | tmp;
				int nw = (w + d[i][s]) % s;
				if (chk[nw] == 0) {
					chk[nw] = 1;
					q.push({ nx, (w + d[i][s]) % s });
				}
				tmp[i] = 0;
			}
		}
	}
	return bitset<101>(0);
}
int main() {
	pre();
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		auto res = go(n);
		if (res.none()) 
			puts("BRAK");
		else {
			bool ok = 0;
			for (int i = 100; i >= 0; --i) {
				if (res[i]) {
					ok = 1;
					printf("1");
				}
				else if (ok) {
					printf("0");
				}
			}
		}
		puts("");
	}
}
