#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; cin >> t;
	while (t--) {
		ll w, h, n; cin >> w >> h >> n;
		ll count = 1;
		while (w % 2 == 0 || h % 2 == 0) {
			if (w % 2 == 0) {
				w /= 2;
				count *= 2;
			}
			if (h % 2 == 0) {
				h /= 2;
				count *= 2;
			}
		}
		if (count >= n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}