#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[101010] = { 1, 1 };
vector<ll> p;
ll cnt;
void go(int s, ll cur, int prev, ll mid) {
	if(s)
		cnt += mid / cur * (s % 2 ? 1 : -1);
	for (int i = prev + 1; i < p.size() && cur * p[i] <= mid; ++i) 
		go(s + 1, cur * p[i], i, mid);
	
}
void pre() {
	for (ll i = 2; i * i <= 5e9; ++i) {
		if (prime[i]) continue;
		for (ll j = i * i; j < 101010; j += i)
			prime[j] = 1;
	}
	for (ll i = 2; i * i <= 5e9; ++i)
		if (!prime[i])p.push_back(i * i);
}
int main() {
	pre();

	int k; scanf("%d", &k);
	ll l = 1, r = 5e9;
	while (l <= r) {
		ll mid = (l + r) / 2;
		cnt = 0;
		go(0, 1, -1, mid);
		if (mid - cnt < k)
			l = mid + 1;
		else if (mid - cnt > k)
			r = mid - 1;
		else {
			bool chk = 0;
			do {
				chk = 0;
				for (int i = 0; i < p.size() && p[i] <= mid; ++i) {
					if (mid % p[i] == 0) {
						--mid;
						chk = 1;
						break;
					}
				}
			} while (chk);
			printf("%lld", mid); return 0;
		}
	}
}
