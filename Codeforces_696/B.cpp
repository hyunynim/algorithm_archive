#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[5050505] = { 1, 1 };
vector<int> p;
void pre() {
	for (ll i = 2; i * i <= 5050505; ++i) {
		if (prime[i]) continue;
		for (ll j = i * i; j < 5050505; j += i)
			prime[j] = 1;
	}
	for (int i = 2; i < 5050505; ++i)
		if (!prime[i])
			p.push_back(i);
}
int main() {
	int t; scanf("%d", &t);
	pre();
	while (t--) {
		int d; scanf("%d", &d);
		int d1 = *lower_bound(p.begin(), p.end(), d + 1);
		int d2 = *lower_bound(p.begin(), p.end(), d1 + d);

		printf("%d\n", d1 * d2);
	}
}