#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll n; scanf("%lld", &n);
		if (n % 4 == 0)
			puts("YES");
		else
			puts("NO");
	}
}