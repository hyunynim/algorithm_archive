#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist(ll xx, ll yy, ll k) {
	return (xx * k) * (xx * k) + (yy * k) + (yy * k);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll d, k; scanf("%lld %lld", &d, &k);
		vector<int> x(d + 1);
		vector<int> y(d + 1);
		ll h = d, w = d;
		x[0] = y[0] = d;
		for (ll i = 1; i <= d; ++i) {
			while (h * h + i * i > d * d)
				--h;
			x[i] = h;
			while (w * w + i * i > d * d)
				--w;
			y[i] = w;
		}
		ll xx = 0, yy = 0;
		
		while (dist(xx, yy, k) < d * d) {
			ll xCnt = (x[xx] - (xx + yy) * k) / k;
			ll yCnt = (y[yy] - (xx + yy) * k) / k;
			if ((xCnt % 2) && dist(xx + 1, yy, k))
				++xx;
			else
				++yy;
		}
		if ((xx + yy) % 2)
			puts("Ashish");
		else
			puts("Utkarsh");
	}
}