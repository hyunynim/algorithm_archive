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
void go2(int s, ll cur, int prev, ll mid, int mp) {
	if (s > 1)
		cnt += mid / cur * (s % 2 ? +1 : -1);
	for (int i = prev + 1; i < p.size() && p[i] < mp && cur * p[i] <= mid; ++i)
		go2(s + 1, cur * p[i], i, mid, mp);

}
void pre() {
	for (ll i = 2; i * i <= 1e9; ++i) {
		if (prime[i]) continue;
		for (ll j = i * i; j < 101010; j += i)
			prime[j] = 1;
	}
	for (ll i = 2; i * i <= 1e9; ++i)
		if (!prime[i])p.push_back(i);
}
int main() {
	pre();
	int n, P; scanf("%d %d", &n, &P);
	int l = 1, r = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int idx = lower_bound(p.begin(), p.end(), P) - p.begin();
		
		cnt = mid / P;

		go2(1, P, -1, mid, P);
		if (cnt > n)
			r = mid - 1;
		else if (cnt < n)
			l = mid + 1;
		else {
			if (mid % P != 0)
				r = mid - 1;
			else {
				printf("%d", mid);
				return 0;
			}
		}
	}
	printf("0");
}
